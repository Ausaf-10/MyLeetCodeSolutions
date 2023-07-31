//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
    int recursion(int indx, int target,int price[]){
        if (indx == 0) return price[0] * target ;
        
        int notPick = 0 + recursion(indx-1, target, price);
        int pick = 0; 
        int rodLength = indx + 1;
        
        if (rodLength <= target) pick = price[indx] + recursion(indx, target-rodLength, price);
        
        return max(pick,notPick);
    }
    
    int memoization(int indx, int target,int price[], vector<vector<int>>& dp){
        if (indx == 0) return price[0] * target ;
        
        if (dp[indx][target]!=-1) return dp[indx][target];
        
        int notPick = 0 + memoization(indx-1, target, price, dp);
        int pick = 0; 
        int rodLength = indx + 1;
        
        if (rodLength <= target) pick = price[indx] + memoization(indx, target-rodLength, price, dp);
        
        return dp[indx][target] = max(pick,notPick);
    }
    
    int tabulation(int price[], int n){
        vector<vector<int>> dp(n, vector<int>(n+1,0));
        // BASE CASE
        for (int i=1; i<=n; i++) dp[0][i] = price[0]*i;
        for (int indx = 1; indx < n; indx++){
            for (int target = 1; target <= n; target++){
                int notPick = 0 + dp[indx-1][target];
                int pick = 0; 
                int rodLength = indx + 1;
                
                if (rodLength <= target) pick = price[indx] + dp[indx][target - rodLength];
                
                dp[indx][target] = max(pick,notPick);
            }
        }
        
        return dp[n-1][n];
    }
    
    int spaceOptimisation(int price[], int n){
        vector<int> prev(n+1,0);
        for (int i=1 ; i<=n; i++) prev[i] = i * price[0];
        
        for (int indx = 1; indx < n; indx++){
            for (int target = 1; target <= n; target++){
                int notPick = 0 + prev[target];
                int pick = 0; 
                int rodLength = indx + 1;
                
                if (rodLength <= target) pick = price[indx] + prev[target - rodLength];
                
                prev[target] = max(pick,notPick);
            }
        }
        
        return prev[n];
    }
    
    int cutRod(int price[], int n) {
        //code her0      
        vector<vector<int>> dp(n, vector<int>(n+1,-1));
        return spaceOptimisation(price, n);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends