//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class DisjointSet{
    vector<int> parent,size;
    public:
        DisjointSet(int n){
            size.resize(n+1,1);
            parent.resize(n+1,0);
            for (int i=0; i<=n; i++) parent[i] = i;
        }

        int findUltimateParent(int node){
            if (parent[node] == node) return node;
            return parent[node] = findUltimateParent(parent[node]);
        }

        void UnionBySize(int u, int v){
            int ulp_u = findUltimateParent(u);
            int ulp_v = findUltimateParent(v);
            if (ulp_u == ulp_v) return ;
            if (size[ulp_u] < size[ulp_v]){
                size[ulp_v]+=size[ulp_u];
                parent[ulp_u] = parent[ulp_v]; 
            }
            else{
                size[ulp_u]+=size[ulp_v];
                parent[ulp_v] = parent[ulp_u]; 
            }
        }
};

class Solution{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[]){
        vector<pair<int,pair<int,int>>> edges;
        for (int i=0; i<V; i++){
            for (auto it : adj[i]){
                int node = i;
                int adjNode = it[0];
                int wt = it[1];
                
                edges.push_back({wt,{node,adjNode}});   
                edges.push_back({wt,{node,adjNode}});   
            }
             
        }
        sort(edges.begin(),edges.end());
        DisjointSet ds(V);
        int mst = 0;
        for (auto it : edges){
            int wt = it.first;
            int u = it.second.first;
            int v = it.second.second;
            
            if (ds.findUltimateParent(u) != ds.findUltimateParent(v)){
                mst+=wt;
                ds.UnionBySize(u,v);
            }
            
        }
        return mst;
        
        
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends