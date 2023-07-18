//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool dfs(int parent,int node ,vector<int> adj[], int vis[]){
        vis[node] = 1;

        for (auto adjacentNodes : adj[node]){
            if (!vis[adjacentNodes]){
                if (dfs(node,adjacentNodes,adj,vis)) return  true;
            }
            else if (adjacentNodes!=parent) return true;
        }
        
        return false;
        
    }
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        int vis[V] = {0};
        for(int i=0; i<V; i++){
            if (vis[i] == 0){
                if (dfs(-1,i,adj,vis)) return true;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends