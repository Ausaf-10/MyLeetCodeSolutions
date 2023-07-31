//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    
    int recursion(int indx, int maxWeight, int val[], int wt[]){
        if (indx == 0){
            return val[0] * (maxWeight / wt[0]);
            
        }
        
        int notPick = 0 + recursion(indx -1, maxWeight, val, wt);
        int pick = -1e9;
        if (wt[indx] <= maxWeight) pick = val[indx] + recursion(indx, maxWeight-wt[indx], val, wt);
        
        return max(pick, notPick);
    }
    
    int memoization(int indx, int maxWeight, int val[], int wt[], vector<vector<int>>& dp){
        if (indx == 0){
            return val[0] * (maxWeight / wt[0]);
            
        }
        
        if (dp[indx][maxWeight]!=-1) return dp[indx][maxWeight];
        
                int notPick = 0 + recursion(indx -1, maxWeight, val, wt);
                int pick = -1e9;
                if (wt[indx] <= maxWeight) pick = val[indx] + recursion(indx, maxWeight-wt[indx], val, wt);
        
        return dp[indx][maxWeight] = max(pick, notPick);
    }
    
    int tabulation(int N, int W, int val[], int wt[]){
        
        vector<vector<int>> dp(N, vector<int>(W+1,0));
        for (int weight = wt[0]; weight <= W; weight++) dp[0][weight] = val[0] * (weight / wt[0]);
        
        for (int indx = 1; indx < N; indx++){
            for (int weight = 0; weight <= W; weight++){
                int notPick = 0 + dp[indx -1][weight];
                int pick = -1e9;
                if (wt[indx] <= weight) pick = val[indx] + dp[indx][weight - wt[indx]];
                dp[indx][weight] = max(pick, notPick);
            }
        }
        
        return dp[N-1][W];
    }
    
    int spaceOptimisation(int N, int W, int val[], int wt[]){
        vector<int> prev(W+1,0);
        for (int weight = wt[0]; weight <= W; weight++) prev[weight] = val[0] * (weight / wt[0]);
        
        for (int indx = 1; indx < N; indx++){
            vector<int> temp(W+1,0);
            for (int weight = 0; weight <= W; weight++){
                int notPick = 0 + prev[weight];
                int pick = -1e9;
                if (wt[indx] <= weight) pick = val[indx] + temp[weight - wt[indx]];
                temp[weight] = max(pick, notPick);
            }
            prev = temp;
        }
        
        return prev[W];
        
    }
    
    int knapSack(int N, int W, int val[], int wt[]){
        // code here


        return spaceOptimisation(N, W, val, wt);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}
// } Driver Code Ends