class Solution {
public:
    bool dfs(int node, vector<int> adj[], vector<int> &vis, vector<int> &color, int iniColor){
        vis[node] = 1, color[node] = iniColor;
        for (auto it : adj[node]){
            if (!vis[it]){
                if (!dfs(it, adj, vis, color, !color[node])) return false;
            }   
            else if (color[node] == color[it]) return false;
        }
        return true;
    }
    bool possibleBipartition(int n, vector<vector<int>>& edges) {
        vector<int> adj[n+1];
        for (auto it : edges){
            int u = it[0], v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> vis(n+1, 0), color(n+1,-1);
        for (int i=1; i<=n; i++){
            if (!vis[i]){
                if (!dfs(i, adj, vis, color, 0)) return false;
            }
        }
        return true;
    }
};