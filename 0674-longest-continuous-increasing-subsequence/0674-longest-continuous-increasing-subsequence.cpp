class Solution {
public:
    int findLengthOfLCIS(vector<int>& arr) {
        int n = arr.size(), maxi = 1;
        vector<int> dp(n, 1);
        for (int indx = 1; indx<n; indx++){
            for (int prevIndx = indx-1; prevIndx >= 0; prevIndx--){
                if (arr[prevIndx] < arr[prevIndx+1]){
                    dp[indx]++;
                }
                else break;
            }
            maxi = max(maxi, dp[indx]);
        }
        return maxi;
    }
};