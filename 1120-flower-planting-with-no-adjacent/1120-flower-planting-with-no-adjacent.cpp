class Solution {
public:
    bool isSafe(vector<int> adj[], int node,vector<int> &color, int n, int col){
        for (auto it : adj[node]){
            // cout << it << " ";
            if (color[it] == col) return false;
        }
        // cout << endl;
        return true;
    }
    bool solve(vector<int> adj[], int node,vector<int> &color, int n){
        if (node == n+1){
            return true;
        }
        for (int i=1; i<=4; i++){
            if (isSafe(adj,node,color,n,i)){

                color[node] = i;
                if (solve(adj,node + 1, color,n) == true) return true;
                
                color[node] = 0;
            }
        }
        return false;
    }
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<int> adj[n+1];
        for (auto it : paths){
            int u = it[0];
            int v = it[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> ds;
        vector<int> color(n+1,-1);
        solve(adj,1,color,n);
        for (int i=1; i<=n; i++){
            ds.push_back(color[i]);
        }
        return ds;
    }
};