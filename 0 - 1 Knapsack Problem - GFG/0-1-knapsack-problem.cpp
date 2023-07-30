//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int recursion(int indx, int remWt, int wt[], int val[]){
        if (indx == 0){
            if (wt[indx] <= remWt) return val[0];
            return 0;
        }
        int notPick = 0 + recursion(indx-1, remWt, wt, val);
        int pick = INT_MIN;
        if (wt[indx]<=remWt) pick = val[indx] + recursion(indx-1,remWt - wt[indx], wt, val);
        return max(pick,notPick);
    }
    
    int memoization(int indx, int W, int wt[], int val[], vector<vector<int>>& dp){
        if (indx == 0){
            if (wt[0] <= W) return val[0];
            return 0;
        }
        if (dp[indx][W]!=-1) return dp[indx][W];
        
        int notPick = 0 + recursion(indx-1, W, wt, val);
        int pick = INT_MIN;
        if (wt[indx] <= W) pick = val[indx] + recursion(indx-1,W - wt[indx], wt, val);
        
        return dp[indx][W] = max(pick,notPick);
    }
    
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int maxWeight, int wt[], int val[], int n) { 
       // Your code here
        // vector<vector<int>> dp(n , vector<int> (remWt + 1, -1));
        
        // vector<vector<int>> dp(n, vector<int>(maxWeight + 1, 0));
        // // BASE CASE
        // for (int W = wt[0]; W <= maxWeight; W++) dp[0][W] = val[0];
        
        // for (int indx = 1; indx<n; indx++){
        //     for (int W = 0; W <= maxWeight; W++){ 
                
                // int notPick = 0 + dp[indx-1][W];
                // int pick = INT_MIN;
                // if (wt[indx] <= W) pick = val[indx] + dp[indx-1][W - wt[indx]];
                
                // dp[indx][W] = max(pick,notPick);
        //     }
        // }
        
        // return dp[n-1][maxWeight];
        
        vector<int> prev(maxWeight + 1, 0);
        for (int W = wt[0]; W<=maxWeight; W++) prev[W] = val[0];
        
        for (int indx = 1; indx<n; indx++){
            vector<int> temp(maxWeight+1,0);
            for (int W = 0; W<=maxWeight; W++){
                int notPick = 0 + prev[W];
                int pick = INT_MIN;
                if (wt[indx] <= W) pick = val[indx] + prev[W - wt[indx]];
                
                temp[W] = max(pick,notPick);
            }
            prev = temp;
        }
        
        return prev[maxWeight];
        
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends