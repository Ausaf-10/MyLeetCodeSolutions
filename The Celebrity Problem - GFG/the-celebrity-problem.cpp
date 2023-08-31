//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int>>& grid, int V) {
        // WE ARE GOING TO CREATE THE ADJACENCY LIST AND WILL DO THIS QUESTION USING INDEGREE AND OUTDEGREE CONCEPT SIMILAR TO 
        
        //                                            TOWN JUDGE

        vector<int> adj[V];
        int n = grid.size(), m = grid[0].size();
        for (int i=0; i<n; i++){
            for (int j=0; j<m; j++){
                if (grid[i][j] == 1){
                    adj[i].push_back(j);
                }
            }
        }
        
        vector<int> inDegree(n,0);
        vector<int> outDegree(n,0);
        for (int i=0; i<n; i++){
            for (auto it : adj[i]){
                inDegree[it]++, outDegree[i]++;
            }
        }
        for (int i=0; i<n; i++){
            if (inDegree[i] == n-1 && outDegree[i] == 0) return i;
        }
        
        return  -1;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}

// } Driver Code Ends