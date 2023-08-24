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

    void dfs(vector<int> adj[], int node, vector<int>& vis){
        vis[node] = 1;
        for (auto it : adj[node]){
            if (!vis[it]){
                dfs(adj,it,vis);
            }
        }
        return ; 
    }

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        V = rooms.size();
       
        
        vector<int> adj[V];
        for (int i=0; i<V; i++){
            for (auto it : rooms[i]){
                adj[i].push_back(it);
            }
        }   

        // return bfs(adj);

        vector<int> vis(V,0);
        dfs(adj,0,vis);
        for (int i=0; i<V; i++) if (!vis[i]) return false;

        return true;
    }
};