//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    void fun(vector<vector<int>> &mat, int row, int col, vector<vector<int>> &vis, vector<string> &ans, string& ds, int n){
        if (row == n-1 && col == n-1){
            ans.push_back(ds);
            return ;
        }
        
        if (row<0 || col<0 || row == n || col == n || mat[row][col] == 0 || vis[row][col] ) return ;
        
        vis[row][col] = 1;
        
        int delrow[4] = {1, 0, 0, -1};
        int delcol[4] = {0, -1, 1, 0};
        string dir ="DLRU";
        for (int i=0; i<4; i++){
            int nrow = delrow[i] + row;
            int ncol = delcol[i] + col;
            ds.push_back(dir[i]);
            fun(mat, nrow, ncol, vis, ans, ds, n);
            ds.pop_back();
        }
        vis[row][col] = 0;
        return ;
    }
    vector<string> findPath(vector<vector<int>> &mat, int n) {
        // Your code goes here
        if (mat[n-1][n-1] != 1) return {};
        vector<vector<int>> vis(n, vector<int>(n,0));
        vector<string> ans;
        string ds;
        fun(mat, 0, 0, vis, ans, ds, n);
        return ans;
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends