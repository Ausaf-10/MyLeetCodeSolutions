typedef pair<int,int> pi;
class Graph {
public:
    vector<vector<int>> *adj;
    int nodes;
    Graph(int n, vector<vector<int>>& edges) {
        nodes = n;
        adj = new vector<vector<int>> [10001];
        for (auto it : edges){
            int u = it[0], v = it[1], wt = it[2];
            adj[u].push_back({v,wt}); 
        }
    }
    int dijkstra(int src, int dest, vector<int>& dist){
        dist[src] = 0;
        priority_queue<pi, vector<pi>, greater<pi>> pq;
        pq.push({0,src});
        while (!pq.empty()){
            auto it = pq.top(); pq.pop();
            int distance = it.first, node = it.second;
            if (node == dest) break;
            for (auto neighbor : adj[node]){
                int v = neighbor[0], wt = neighbor[1];
                if (dist[v] > distance + wt){
                    dist[v] = distance + wt;
                    pq.push({dist[v], v});
                }
            } 
        }   
        return dist[dest] == 1e9 ? -1 : dist[dest];
    }    
    void addEdge(vector<int> it) {
        int u = it[0], v = it[1], wt = it[2];
        adj[u].push_back({v,wt});
    }   
    
    int shortestPath(int node1, int node2) {
        vector<int> dist(nodes,1e9);
        return dijkstra(node1, node2, dist);
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */