class Solution {
public: 
    int n;
    int recursion(int indx, int prevIndx, vector<int>& arr){
        if (indx == n) return 0;
        int pick = -1e9;
        if (prevIndx == -1 || arr[indx] > arr[prevIndx]){
            pick = 1 + recursion(indx+1, indx, arr);
        }
        int notPick = 0 + recursion(indx + 1, prevIndx, arr);
        return max(pick, notPick);
    }
    int tabulation(vector<int>& arr){
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        for (int indx = n-1; indx>=0; indx--){
            for (int prevIndx = -1; prevIndx < indx; prevIndx++){
                int pick = -1e9;
                if (prevIndx == -1 || arr[indx] > arr[prevIndx]){
                    pick = 1 + dp[indx+1][indx+1];
                }
                int notPick = 0 + dp[indx + 1][prevIndx+1];
                dp[indx][prevIndx+1] = max(pick, notPick);
            }
        }
        return dp[0][0];
    }
    int binarySearch(vector<int>& arr){
        int maxi = 1;
        vector<int> temp;
        temp.push_back(arr[0]);
        for (int i=1; i<n; i++){
            int lb = lower_bound(temp.begin(), temp.end(), arr[i]) - temp.begin();
            if (lb == temp.size()){
                temp.push_back(arr[i]);
            }
            else temp[lb] = arr[i];
            maxi = max(maxi, (int)temp.size());
        }
        return maxi;
    }
    int lengthOfLIS(vector<int>& arr) {
        n = arr.size();
        // return recursion(0, -1, arr);
        // return tabulation(arr);
        return binarySearch(arr);
    }
};