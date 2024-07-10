class Solution {
public:  
    int V;
    void dfs(vector<vector<int>>& adj, int node, vector<int>& path,vector<vector<int>>& ans){
        path.push_back(node);
        for (auto it : adj[node]){
            dfs(adj, it, path, ans);
        }
        if (node == V-1){
            ans.push_back(path);
        }
        path.pop_back();
        return;
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& adj) {
        V = adj.size();
        vector<vector<int>> ans;
        vector<int> path;
        dfs(adj, 0, path, ans);

        return ans; 


    }
};