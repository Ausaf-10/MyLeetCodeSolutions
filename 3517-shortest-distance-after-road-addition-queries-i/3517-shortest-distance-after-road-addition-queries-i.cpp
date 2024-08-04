class compare{
    public:
        bool operator()(const pair<int,int>& a,const pair<int,int>& b){
            return (a.first > b.first );
        }      
};
class Solution {
public:
    int V;
    vector<int> dijkstra(vector<vector<int>> adj[], int src){
        vector<int> dist(V);
        for (int i=0; i<V; i++) dist[i] = 1e9;
        dist[src] = 0;
        priority_queue<pair<int,int>, vector<pair<int,int>>, compare> minHeap;
        minHeap.push({0,src});
        
        while (!minHeap.empty()){
            int distance = minHeap.top().first;
            int node = minHeap.top().second;
            minHeap.pop();
            
            for (auto &v : adj[node]){
                int neighbor = v[0];
                int wt = v[1];
                if (dist[neighbor] > distance + wt){
                    dist[neighbor] = distance + wt; 
                    minHeap.push({dist[neighbor],neighbor});
                }
            }
            
            
        }
        
        return dist;
    }
    vector<int> shortestDistanceAfterQueries(int N, vector<vector<int>>& queries) {
        V= N;
        vector<vector<int>> adj[V];
        for (int i=0; i<V; i++){
            if (i == V-1) break;
            adj[i].push_back({i+1,1});
        }
        vector<int> ans;
        for (auto it : queries){
            adj[it[0]].push_back({it[1],1});
            vector<int> dist = dijkstra(adj, 0);
            int x = dist[V-1];
            ans.push_back(x);
        }
        return ans;
    }
};