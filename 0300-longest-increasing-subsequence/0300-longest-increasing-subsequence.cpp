class Solution {
public:
    int n;
    int recursion(vector<int>& arr, int indx, int prevIndx){
        if (indx == n) return 0;
        int include = -1e9;
        if (prevIndx == -1 || arr[indx] > arr[prevIndx]){
            include = 1 + recursion(arr, indx+1, indx);
        }
        int notInclude = 0 + recursion(arr, indx+1, prevIndx);
        return max(include, notInclude);
    }
    int tabulation(vector<int>& arr){
        vector<vector<int>> dp(n+1, vector<int>(n+1,0));
        for (int indx=n-1; indx>=0; indx--){
            for (int prevIndx = -1; prevIndx<indx; prevIndx++){
                int include = -1e9;
                if (prevIndx == -1 || arr[indx] > arr[prevIndx]){
                    include = 1 + dp[indx+1][indx+1];
                }
                int notInclude = 0 + dp[indx+1][prevIndx+1];
                dp[indx][prevIndx+1] = max(include, notInclude);
            }
        }
        return dp[0][0];
    }
    int lengthOfLIS(vector<int>& arr) {
        n = arr.size();       
        // return recursion(arr, 0, -1);
        return tabulation(arr); 
    }
};