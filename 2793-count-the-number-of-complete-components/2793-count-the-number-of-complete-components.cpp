class Solution {
public:
    int V;
    void dfs(vector<int> adj[], int node, vector<int>& vis, vector<int>& path, vector<vector<int>>& ans){
        vis[node] = 1, path.push_back(node);
        for (auto it : adj[node]){
            if (!vis[it]){
                dfs(adj, it, vis, path, ans);
            }
        }
        return ;
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        V = n;
        vector<int> adj[V];
        for (auto it : edges){
            int u = it[0], v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> vis(V,0);

        vector<vector<int>> ans;
        for (int i=0; i<V; i++){
            if (!vis[i]){
                vector<int> path;
                dfs(adj, i, vis, path, ans);
                ans.push_back(path);
            }
        }
        // ans = {{0,1,2},{3,4},{5}}
        int cnt = 0;
        for (auto it : ans){
            if (it.size() == 1){
                cnt++;
                continue;
            }
            int numberOfVertices = it.size();
            int numberOfEdges = 0;
            for (auto j : it){
                numberOfEdges+=adj[j].size();
            }
            numberOfEdges/=2;
            int val = (numberOfVertices*(numberOfVertices-1))/2;
            if (numberOfEdges == val) cnt++;
        }
        return cnt;
    }
};