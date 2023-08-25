//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    // i: 1->n-1 , j: n-1 -> 1
    int recursion(int i, int j, int arr[]){
        if (i == j) return 0;   // SINGLE ARRAY KO AAPAS MEIN MULTIPLY KRNE MEIN 0 HI STEPS LAGENGE
        int mini = 1e9;
      
        // USING A FOR LOOP BCOZ WE NEED TO GET ALL THE POSSIBLE PARTITION
        for (int k=i; k<j; k++){
            
            int steps = recursion(i,k,arr) + recursion(k+1,j,arr) + (arr[i-1] * arr[k] * arr[j]);
            
            // 1. f(i,k) -> PEHLE PARTITION KO AAPAS MEIN MULTIPLY KRNE MEIN KITNE STEPS LAGENGE!
            // 2. f(K+1,J) -> DUSRA PARTITION KO AAPAS MEIN MULTIPLY KRNE MEIN KITNE STEPS LAGENGE!
            // 3. NOW I HAVE GOT THE TWO FINAL MATRIX AND NOW THE NO OF STEPS TO MULTIPLY THESE 2 WILL BE THIS :  (arr[i-1] * arr[k] * arr[j])
            // AT THE EOD U NEED TO RETURN THE MINIMAL OF ALL THE STEPS
            
            mini = min(mini, steps);
        }
        
        return mini;
    }
    // FOR MEMOIZATION, WE HAVE 2 STATES SO A 2D DP IS REQUIRED ! 
    int memoization(int i, int j, int arr[],vector<vector<int>> dp){
        if (i == j) return 0;   // SINGLE ARRAY KO AAPAS MEIN MULTIPLY KRNE MEIN 0 HI STEPS LAGENGE
        int mini = 1e9;
        
        if (dp[i][j]!=-1) return dp[i][j];
        
        // USING A FOR LOOP BCOZ WE NEED TO GET ALL THE POSSIBLE PARTITION
        
        for (int k=i; k<j; k++){
            
            int steps = memoization(i,k,arr,dp) + memoization(k+1,j,arr,dp) + (arr[i-1] * arr[k] * arr[j]);
            
            // 1. f(i,k) -> PEHLE PARTITION KO AAPAS MEIN MULTIPLY KRNE MEIN KITNE STEPS LAGENGE!
            // 2. f(K+1,J) -> DUSRA PARTITION KO AAPAS MEIN MULTIPLY KRNE MEIN KITNE STEPS LAGENGE!
            // 3. NOW I HAVE GOT THE TWO FINAL MATRIX AND NOW THE NO OF STEPS TO MULTIPLY THESE 2 WILL BE THIS :  (arr[i-1] * arr[k] * arr[j])
            // AT THE EOD U NEED TO RETURN THE MINIMAL OF ALL THE STEPS
            
            mini = min(mini, steps);
        }
        
        return dp[i][j] = mini;
    }
    
    int tabulation(int n, int arr[]){
        // BOTTOM UP APPROACH 
        vector<vector<int>> dp(n, vector<int>(n,0)); 
        for (int i=0; i<n; i++) dp[i][i] = 0;
        for (int i=n-1; i>=1; i--){
            for (int j=i+1; j<n; j++){
                int mini = 1e9;    
                for (int k=i; k<j; k++){
                    
                    int steps = dp[i][k] + dp[k+1][j] + (arr[i-1] * arr[k] * arr[j]);
                    
                    // 1. f(i,k) -> PEHLE PARTITION KO AAPAS MEIN MULTIPLY KRNE MEIN KITNE STEPS LAGENGE!
                    // 2. f(K+1,J) -> DUSRA PARTITION KO AAPAS MEIN MULTIPLY KRNE MEIN KITNE STEPS LAGENGE!
                    // 3. NOW I HAVE GOT THE TWO FINAL MATRIX AND NOW THE NO OF STEPS TO MULTIPLY THESE 2 WILL BE THIS :  (arr[i-1] * arr[k] * arr[j])
                    // AT THE EOD U NEED TO RETURN THE MINIMAL OF ALL THE STEPS
                    
                    mini = min(mini, steps);
                }
                
                dp[i][j] = mini;
            }
        } 
        
        return dp[1][n-1];
    }
    
    int matrixMultiplication(int n, int arr[]){
        int i = 1, j = n-1;
        // MAX POSSIBLE VALUE OF i and j WILL BE n-1 ONLY SO CREATE A 2D DP OF SIZE N
        vector<vector<int>> dp(n, vector<int>(n,-1));
        return tabulation(n,arr);
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