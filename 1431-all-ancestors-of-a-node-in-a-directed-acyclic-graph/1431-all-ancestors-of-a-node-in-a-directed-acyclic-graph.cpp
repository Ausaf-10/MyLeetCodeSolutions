class Solution {
public:
    void dfs(int node, vector<int> adj[], set<int>& st){
        if (st.empty() || st.find(node) == st.end()){
            st.insert(node);
        }
        else return ;
        for (auto& it : adj[node]){
            dfs(it, adj, st);
        }
        return ;
    }
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<int> adj[n];
        for (auto it : edges){
            adj[it[1]].push_back(it[0]);
        }
        vector<vector<int>> res(n);
        for (int i=0; i<n; i++){
            set<int> st;
            dfs(i, adj, st);
            st.erase(i);
            vector<int> temp(st.begin(),st.end());
            res[i] = temp;
        }
        return res;
    }
};