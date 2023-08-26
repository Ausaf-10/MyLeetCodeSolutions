//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//Back-end complete function Template for C++

class Solution {
  public:
    // indx: n -> 0
    int recursion(int indx, vector<int>& cost){
        if (indx == 0 || indx == 1) return cost[indx];
        int oneStep = recursion(indx-1,cost);
        int twoStep = recursion(indx-2,cost);
        
        if (indx == cost.size()) return min(oneStep,twoStep);
        
        return min(oneStep,twoStep) + cost[indx];
    }
    
    int memoization(int indx, vector<int>& cost, vector<int>& dp){
        if (indx == 0 || indx == 1) return cost[indx];
        int oneStep = memoization(indx-1, cost, dp);
        int twoStep = memoization(indx-2, cost, dp);
        
        if (indx == cost.size()) return dp[indx] =  min(oneStep,twoStep);
        
        return dp[indx] = min(oneStep,twoStep) + cost[indx];
    }
    
    int tabulation(vector<int>& cost ,int n){
        vector<int> dp(n+1,0);
        dp[0] = cost[0], dp[1] = cost[1];
        for (int indx=2; indx<=n; indx++){
            
            int oneStep = dp[indx-1];
            int twoStep = dp[indx-2];
            
            if (indx == cost.size()){
                dp[indx] =  min(oneStep,twoStep);
                break;
            }
            
            dp[indx] = min(oneStep,twoStep) + cost[indx];
        }
        
        return dp[n];
    }
    
    int spaceOptimization(vector<int>& cost ,int n){
        
        int prev2 = cost[0], prev = cost[1];
        for (int indx=2; indx<=n; indx++){
            
            int oneStep = prev;
            int twoStep = prev2;
            
            if (indx == cost.size()){
                int cur =  min(oneStep,twoStep);
                prev2 = prev, prev = cur;
                break;
            }
            
            int cur = min(oneStep,twoStep) + cost[indx];
            prev2 = prev, prev = cur;
        }
        
        return prev;
    }
    
    int minCostClimbingStairs(vector<int>& cost ,int n) {
        //Write your code here
        // int n = cost.size();
        // vector<int> dp(n+1,-1);
        
        return tabulation(cost, n);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        vector<int>cost(N);
        
        for(int i=0 ; i<N ; i++){
            cin>>cost[i];
        }

        Solution ob;
        cout<<ob.minCostClimbingStairs(cost,N);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends