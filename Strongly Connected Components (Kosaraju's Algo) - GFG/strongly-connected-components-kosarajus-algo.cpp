//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	private:
	// THIS DFS IS USED TO GET THE NODES ACCORDING TO THEIR FINISHING TIME ! 
    void dfs(vector<vector<int>>& adj, int node, vector<int>& vis, stack<int>& stk){
	    vis[node] =1;
	    for (auto it : adj[node]){
	        if (!vis[it]){
	            dfs(adj, it, vis, stk);
	        }
	    }
	    stk.push(node);
	    return ;
    }
    // THIS IS THE DFS FOR THE ADJACENCY LIST WHEN THE EDGES HAVE BEEN REVERSED!
    void dfs3(vector<int> transposeAdj[], int node, vector<int>& vis){
        vis[node] =1;
	    for (auto it : transposeAdj[node]){
	        if (!vis[it]){
	            dfs3(transposeAdj, it, vis);
	        }
	    }
	    
	    return ;
    }
	public:
    int kosaraju(int V, vector<vector<int>>& adj){
        // 1. SORT THE EDGES ACCORDING TO THE FINISHING TIME -> CALL THE DFS FOR EVERY NODE!
        stack<int> stk;
        vector<int> vis(V,0);
        
        // I AM GONG TO CALL THE DFS FOR EVERY NODE, so that every one is in stack
        for (int i=0; i<V; i++){
            if (!vis[i]){
                dfs(adj,i,vis,stk);
            }
        }
        
        
        // 2. REVERSE ALL EDGES 
        vector<int> transposeAdj[V]; // THAT IS GOING TO CONTAIN THE REVERSE EDGES
        for (int i=0; i<V; i++){
            vis[i] = 0;                 // DOING THIS SO THAT WE CAN REUSE THIS VISTED ARRAY AND MARKING EVERY ONE OF THEM AS UNMARKED
            for (auto it : adj[i]){
                // i->it, this is the edges
                // but we want the reverse edge
                transposeAdj[it].push_back(i);
            }
        }
        
        // 3. NOW CALL THE DFS AND COUNT THE SCC
        int scc = 0;
        while (!stk.empty()){
            int node = stk.top(); stk.pop();
            if (!vis[node]){
                dfs3(transposeAdj,node, vis);
                scc++;
            }
        }
        
        return scc;
        
    }
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<vector<int>> adj(V);

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends