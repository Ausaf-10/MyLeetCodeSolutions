class Solution {
public:
    vector<int> shortestAlternatingPaths(int V, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<pair<int,int>> adj[V];
        // RED-> 1 , BLUE->0

        for(auto it : redEdges){
            adj[it[0]].push_back({it[1],1});
        } 
        
        for(auto it : blueEdges){
            adj[it[0]].push_back({it[1],0});
        }

        vector<int> distance(V,-1);
        distance[0] = 0;

        int dis = 1;

        vector<vector<int>> vis(V, vector<int>(2,0));

        queue<pair<int,int>> q; q.push({0,-1}); // NODE->COLOR
        vis[0][0] = 1, vis[0][1] = 1;

        while (!q.empty()){
            int size = q.size();
            for  (int i=0; i<size; i++){
                auto Node = q.front(); q.pop();
                int node = Node.first, color = Node.second;

                for (auto it : adj[node]){
                    int v = it.first, newColor = it.second;
                    if (!vis[v][newColor] && newColor!=color){
                        vis[v][newColor] = 1;
                        q.push({v,newColor});
                        if (distance[v] == -1)
                            distance[v] = dis;
                    } 
                }
            }    
            dis++;        
        }

        return distance;
    }
};