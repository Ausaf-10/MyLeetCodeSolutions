//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class DisjointSet{
    public:
        vector<int> parent,size;
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

class Solution {
  private:
    bool isValid( int row, int col, int n, int m){
        if (row>=0 && row<n && col>=0 && col<m ) return true;
        return false;
    }
  public:
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        DisjointSet ds(n*m);
        vector<vector<int>> vis(n,vector<int>(m,0));
        int cnt = 0;
        vector<int> ans;
        for (auto it : operators){
            int row = it[0];
            int col = it[1];
            if (vis[row][col] == 1){
                ans.push_back(cnt);
                continue;
            }
            vis[row][col] = 1;
            cnt++;
            
            int delrow[4] = {-1,0,1,0};
            int delcol[4] = {0,1,0,-1};
            for (int i=0; i<4; i++){
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];
                
                if (isValid(nrow,ncol,n,m)){
                    if (vis[nrow][ncol] == 1){
                        int nodeNo = row * m + col;
                        int adjNode = nrow * m + ncol;
                        if (ds.findUltimateParent(nodeNo) != ds.findUltimateParent(adjNode)){
                            ds.UnionBySize(nodeNo,adjNode);
                            cnt--;
                        }
                    }
                }
            }
            
            ans.push_back(cnt);
        }
        
        
        return ans;
        
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,k; cin>>n>>m>>k;
        vector<vector<int>> a;
        
        for(int i=0; i<k; i++){
            vector<int> temp;
            for(int j=0; j<2; j++){
                int x; cin>>x;
                temp.push_back(x);
            }
            a.push_back(temp);
        }
    
        Solution obj;
        vector<int> res = obj.numOfIslands(n,m,a);
        
        for(auto x : res)cout<<x<<" ";
        cout<<"\n";
    }
}

// } Driver Code Ends