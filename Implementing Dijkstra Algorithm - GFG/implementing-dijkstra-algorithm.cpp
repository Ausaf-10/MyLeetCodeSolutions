//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// class compare{
//     bool operator()(pair<int,int>& a, pair<int,int>& b){
//         return (a.first > b.first );
//     }      
// };
class Solution{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int src){
        // Code here
        vector<int> dist(V);
        for (int i=0; i<V; i++) dist[i] = 1e9;
        dist[src] = 0;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minHeap;
        minHeap.push({0,src});
        
        while (!minHeap.empty()){
            int distance = minHeap.top().first;
            int node = minHeap.top().second;
            minHeap.pop();
            
            for (auto v : adj[node]){
                int neighbor = v[0];
                int wt = v[1];
                
                if (dist[neighbor] > distance + wt){
                     dist[neighbor] = distance + wt; 
                     minHeap.push({dist[neighbor],neighbor});
                }
                
            }
            
            
        }
        
        return dist;
        
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
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}


// } Driver Code Ends