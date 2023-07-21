//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

#include <bits/stdc++.h>
// class compare{
//     public:
//         bool operator()(const pair<int,int>& a,const pair<int,int>& b){
//             return (a.first > b.first );
//         }      
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
       
        // priority_queue<pair<int,int>, vector<pair<int,int>>, compare> minHeap;
        // minHeap.push({0,src});
        
        set<pair<int,int>> st;
        st.insert({0,src});
        
        while (!st.empty()){
            auto it = *(st.begin());
            int node = it.second;
            int distance = it.first;
            st.erase(it);
            
            for (auto v : adj[node]){
                int neighbor = v[0];
                int wt = v[1];
                
                
                if (dist[neighbor] > distance + wt){
                    if (dist[neighbor]!=1e9) st.erase({dist[neighbor],neighbor});
                    
                    dist[neighbor] = distance + wt; 
                    st.insert({dist[neighbor],neighbor});
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