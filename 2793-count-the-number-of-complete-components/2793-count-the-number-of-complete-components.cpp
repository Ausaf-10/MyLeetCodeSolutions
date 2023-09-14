class Solution {
public:
    int V;
    void dfs(vector<int> adj[], int node, vector<int>& vis, int& numberOfVertices, int& numberOfEdges){
        vis[node] = 1, numberOfVertices+=1, numberOfEdges+=adj[node].size();

        for (auto it : adj[node]){
            if (!vis[it]){
                dfs(adj, it, vis, numberOfVertices, numberOfEdges);
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
        int cnt = 0;
        for (int i=0; i<V; i++){
            if (!vis[i]){
                int numberOfVertices = 0, numberOfEdges = 0;
                dfs(adj, i, vis, numberOfVertices, numberOfEdges);
                numberOfEdges/=2;
                int val = (numberOfVertices*(numberOfVertices-1))/2;
                if (numberOfEdges == val) cnt++;
            }
        }
        return cnt;
    }
};