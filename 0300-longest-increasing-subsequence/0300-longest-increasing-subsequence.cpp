class Solution {
public:
    int recursion(int indx, int prevIndx, vector<int>& arr){
        if (indx == arr.size()) return 0;
        
        int len = 0 + recursion(indx+1, prevIndx, arr);
        
        if (prevIndx == -1 || arr[indx] > arr[prevIndx]){
            len = max(len, 1 + recursion(indx+1, indx, arr));
        } 

        return len;
    }

    int memoization(int indx, int prevIndx, vector<int>& arr, vector<vector<int>>& dp){
        if (indx == arr.size()) return 0;
        
        if (dp[indx][prevIndx+1]!=-1) return dp[indx][prevIndx+1];

        int len = 0 + memoization(indx+1, prevIndx, arr, dp);
        
        if (prevIndx == -1 || arr[indx] > arr[prevIndx]){
            len = max(len, 1 + memoization(indx+1, indx, arr, dp));
        } 

        return dp[indx][prevIndx + 1] = len;
    }

    int tabulation(vector<int>& arr){
        int n = arr.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1,0));

        for (int indx = n-1; indx>=0; indx--){
            for (int prevIndx = indx - 1; prevIndx>=-1; prevIndx--){
                int len = 0 + dp[indx+1][prevIndx + 1];
                
                if (prevIndx == -1 || arr[indx] > arr[prevIndx]){
                    len = max(len, 1 + dp[indx+1][indx + 1]);
                } 

                dp[indx][prevIndx + 1] = len;
            }
        }

        return dp[0][0];
    }

    int spaceOptimization(vector<int>& arr){
        int n = arr.size();
        vector<int>prev (n+1,0);

        for (int indx = n-1; indx>=0; indx--){
            vector<int> temp (n+1,0);
            for (int prevIndx = indx - 1; prevIndx>=-1; prevIndx--){
                int len = 0 + prev[prevIndx + 1];
                
                if (prevIndx == -1 || arr[indx] > arr[prevIndx]){
                    len = max(len, 1 + prev[indx + 1]);
                } 

                temp[prevIndx + 1] = len;
            }
            prev = temp;
        }

        return prev[0];
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n+1,-1));
        // return memoization(0, -1, nums, dp);    
        return spaceOptimization(nums);
    }
};