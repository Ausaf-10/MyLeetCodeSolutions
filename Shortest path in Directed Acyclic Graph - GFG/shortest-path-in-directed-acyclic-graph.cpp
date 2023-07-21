//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    void dfs(vector<pair<int,int>> adj[], int node, vector<int>& vis, stack<int>& stk){
        vis[node] = 1;
        for (auto it : adj[node]){
            int neighbor = it.first;
            int wt = it.second;
            if (!vis[neighbor]){
                dfs(adj,neighbor,vis,stk);
            }
        }
        
        stk.push(node);
        return ;
    }
     vector<int> shortestPath(int V,int M, vector<vector<int>>& edges){
        // code here
        vector<pair<int,int>> adj[V];
        for (int i=0; i<M; i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            
            adj[u].push_back({v,wt});
        }
        stack<int> stk;
        vector<int> vis(V,0);
        for (int i=0; i<V; i++){
            if (!vis[i]){
                dfs(adj,i,vis,stk);
            }
        }
        
        vector<int> dist(V,0);
        for (int i=0; i < V; i++) dist[i] = 1e9;
        dist[0] = 0;
        
        while (!stk.empty()){
            int node = stk.top();
            stk.pop();
            
            for (auto it : adj[node]){
                int v = it.first;
                int wt = it.second;
                dist[v] = min(dist[v], wt + dist[node]);
            }
        }
        
        for (int i=0; i<V; i++){
            if (dist[i] == 1e9) dist[i] = -1;
        }
        
        return dist;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends