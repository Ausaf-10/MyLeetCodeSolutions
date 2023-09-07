//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		

	public:
	int maxSumIS(int arr[], int n)  {  
	    // Your code goes here
	    vector<int> temp;
	    vector<int> dp(n,1), hash(n,0);
	    for (int i=0; i<n; i++) dp[i] = arr[i];
	    
	    int lastIndx = -1, maxLen = -1;
	    for (int i=0; i<n; i++){
	        for(int prev = 0; prev<i; prev++){
	            if (arr[i] > arr[prev] && dp[prev] + arr[i] > dp[i]){
                    dp[i] = dp[prev] + arr[i];
                    hash[i] = prev;
	            }
	        }
	    }
	    
	    int maxi = -1e9;
	    for (int i=0; i<n; i++){
	        maxi = max(maxi, dp[i]);
	    }
	 
	    return maxi;
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