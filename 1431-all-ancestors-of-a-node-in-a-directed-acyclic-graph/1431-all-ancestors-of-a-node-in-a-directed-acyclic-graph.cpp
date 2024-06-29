class Solution {
public:
    void dfs(int node, int ancestor, vector<int> adj[], vector<vector<int>>& res){
        for (auto &it : adj[node]){
            if (res[it].size() == 0 || res[it].back() != ancestor){
                res[it].push_back(ancestor);
                dfs(it, ancestor, adj, res);
            }
        }
        return ;
    }
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<int> adj[n];
        for (auto it : edges){
            adj[it[0]].push_back(it[1]);
        }
        vector<vector<int>> res(n);
        for (int i=0; i<n; i++){
            dfs(i, i, adj, res);
        }
        return res;
    }
};