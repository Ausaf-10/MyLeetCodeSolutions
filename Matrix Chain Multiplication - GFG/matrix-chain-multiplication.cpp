//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int recursion(int i, int j, int arr[], int n){
        if (i == j) return 0;
        int mini = 1e9;
        for (int k = i; k < j; k++){
            int steps = arr[i-1]*arr[k]*arr[j] + recursion(i,k,arr,n) + recursion(k+1,j,arr,n);
        
            mini = min(mini, steps);        
        }
        
        return mini;
    }
    
    int memoization(int i, int j, int arr[], int n, vector<vector<int>> &dp){
        if (i == j) return 0;
        if (dp[i][j] != -1) return dp[i][j];
        int mini = 1e9;
        for (int k = i; k < j; k++){
            int steps = arr[i-1]*arr[k]*arr[j] + memoization(i,k,arr,n, dp) + memoization(k+1,j,arr,n, dp);
        
            mini = min(mini, steps);        
        }
        
        return dp[i][j] = mini;
    }
    
    int tabulation(int N, int arr[]){
        vector<vector<int>> dp(N, vector<int>(N,0));
        for (int i=1; i<N; i++) dp[i][i] = 0;
        
        for (int i=N-1; i>=1; i--){
            for (int j=i+1; j<N; j++){
                if (i > j) continue;
                int mini = 1e9;
                for (int k = i; k < j; k++){
                    int steps = arr[i-1]*arr[k]*arr[j] + dp[i][k] + dp[k+1][j];
                
                    mini = min(mini, steps);        
                }
                
                dp[i][j] = mini;
            }
        }
        
        return dp[1][N-1];
    }
    
    int matrixMultiplication(int N, int arr[]){
        // code here
        // vector<vector<int>> dp(N, vector<int>(N,-1));
        return tabulation(N, arr);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}
// } Driver Code Ends