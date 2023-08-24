class Solution {
public:
    int V;
    bool bfs(vector<int> adj[]){
       
        vector<int> vis(V,0);
        queue<int> q; q.push(0); vis[0] = 1;

        while (!q.empty()){
            int node = q.front(); q.pop();
            for (auto it : adj[node]){
                if (!vis[it]){
                    vis[it] = 1;
                    q.push(it);
                }
            }
        }

        for (int i=0; i<V; i++){
            if (!vis[i]) return false;
        }

        return true;
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        V = rooms.size();
       
        
        vector<int> adj[V];
        for (int i=0; i<V; i++){
            for (auto it : rooms[i]){
                adj[i].push_back(it);
                // adj[it].push_back(i);
            }
        }

        return bfs(adj);
    }
};