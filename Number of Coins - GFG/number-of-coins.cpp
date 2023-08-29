//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	// ISS PARTICULAR QUES MEIN AGAR INIDAN CURRECNY HAI TOH KOI DIKKAT NHI HAI COZ DO CONSECUTIVE DENOMINATIONS KA SUM KABHI BHI EK DENOMINATION
    // SE ZYAADA NHI HO SKTA HAI AND THAT IS Y WE CAN USE GREEDY APPROACH 
    // eg-> {1,2,5,10,20,50,100,500,1000}, INMEIN KIN HI BHI DO KA SUM EK SE ZYAADA NHI HAI AND THAT IS Y WE CAN USE GREEDY 
    
    // BUT, {1,6,5,9}, IN THIS THE GREEEDY APPROACH FAILS BCOZ LETS SAY TARGET = 11, THEN ACCORDING TO GREEDY WE WILL USE 9 + 1 + 1
    // BUT A 6 + 5 IS A BETTER APPROACH AND HENCE GREEDY FAILS OVER HERE!!!!
    
	public:
	// indx: n-1 -> 0, target: target->0
	int recursion(int arr[], int indx, int target){
        if (indx == 0){
            if (target % arr[0] == 0) return target/arr[0];     // JITNE COINS LE SKTE HO LE LO 
            else return 1e9;                                    // YAHAN PE TOH AAP KABHI BHI KOI BHI COINS NHI UTHA PAOGE 
        }
        int pick = 1e9;
	    if (arr[indx] <= target) pick = 1 + recursion(arr, indx, target - arr[indx]);
	    int notPick = 0 + recursion(arr, indx-1, target);

	    return min(pick, notPick);
	}
	
	int memoization(int arr[], int indx, int target, vector<vector<int>>& dp){
	    if (indx == 0){
            if (target % arr[0] == 0) return target/arr[0];
            else return 1e9;  
	    }
	    if (dp[indx][target]!=-1) return dp[indx][target];
	    int pick = 1e9;
	    if (arr[indx] <= target) pick = 1 + memoization(arr, indx, target - arr[indx], dp);
	    int notPick = 0 + memoization(arr, indx-1, target, dp);

	    return dp[indx][target] = min(pick, notPick);
	}
	
	int tabulation(int arr[], int n, int amount){
        vector<vector<int>> dp(n, vector<int>(amount+1,0));
       // BASE CASE
       for (int j=0; j<=amount; j++) dp[0][j] = (j%arr[0] == 0) ? (j/arr[0]) : 1e9;
       
       for (int indx =1; indx<n; indx++){
           for (int target=0; target<=amount; target++){
                int pick = 1e9;
        	    if (arr[indx] <= target) pick = 1 + dp[indx][target - arr[indx]];
        	    int notPick = 0 + dp[indx-1][target];
        
        	    dp[indx][target]  = min(pick, notPick);
           }
       }
	    
	   return (dp[n-1][amount] == 1e9) ? -1 : dp[n-1][amount];
	}
	
	int minCoins(int coins[], int n, int target) { 
	    // Your code goes here
	    vector<vector<int>> dp(n, vector<int>(target+1,-1));
	    return tabulation(coins,n,target);
	} 
	  
};

//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int v, m;
        cin >> v >> m;

        int coins[m];
        for(int i = 0; i < m; i++)
        	cin >> coins[i];

      
	    Solution ob;
	    cout << ob.minCoins(coins, m, v) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends