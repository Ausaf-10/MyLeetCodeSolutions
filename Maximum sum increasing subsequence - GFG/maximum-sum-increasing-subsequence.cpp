//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		

	public:
	
	int recursion(int indx, int prevIndx, int arr[], int n){
	       if (indx == n) return 0;
	       
	       int len = 0 + recursion(indx+1, prevIndx, arr, n);
	       
	       if (prevIndx == -1 || arr[indx] > arr[prevIndx]){
	           len = max(arr[indx] + recursion(indx + 1, indx, arr, n), len);
	       }
	       
	       return len;
	}
	
	int memoizatoin(int indx, int prevIndx, int arr[], int n, vector<vector<int>> &dp){
	    if (indx == n) return 0;
	    if (dp[indx][prevIndx + 1]!=-1) return  dp[indx][prevIndx + 1];
	    
	    int len = 0 + memoizatoin(indx+1, prevIndx, arr, n, dp);
       
        if (prevIndx == -1 || arr[indx] > arr[prevIndx]){
            len = max(arr[indx] + memoizatoin(indx + 1, indx, arr, n, dp), len);
        }
       
        return dp[indx][prevIndx + 1] = len;
        
	}
	
	int maxSumIS(int arr[], int n)  {  
	    // Your code goes here
	   // vector<int> dp(n,1);
	   // for (int i=0; i<n; i++) dp[i] = arr[i];
	    
	   // int lastIndx = -1, maxLen = -1;
	   // for (int i=0; i<n; i++){
	   //     for(int prev = 0; prev<i; prev++){
	   //         if (arr[i] > arr[prev] && dp[prev] + arr[i] > dp[i]){
    //                 dp[i] = dp[prev] + arr[i];
    //                 hash[i] = prev;
	   //         }
	   //     }
	   // }
	    
	   // int maxi = -1e9;
	   // for (int i=0; i<n; i++){
	   //     maxi = max(maxi, dp[i]);
	   // }
	    vector<vector<int>> dp(n+1, vector<int>(n+1,-1));
	    return memoizatoin(0, -1, arr,n, dp);
	}  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

      

	    Solution ob;
	    cout << ob.maxSumIS(a, n) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends