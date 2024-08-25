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
    int tabulation1(vector<int>& arr){
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        for (int indx=n-1; indx>=0; indx--){
            for (int prevIndx=-1; prevIndx < indx; prevIndx++){
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
    int tabulation(vector<int>& arr){
        int maxi = 1, maxIndx = -1;
        vector<int> dp(n, 1), hash(n, 0);
        for (int i=0; i<n; i++) hash[i] = i;
        for (int indx = 0; indx < n; indx++){
            for (int prevIndx = 0; prevIndx < indx; prevIndx++){
                if (arr[indx] > arr[prevIndx] && dp[indx] < 1 + dp[prevIndx]){
                    dp[indx] = 1 + dp[prevIndx];
                    hash[indx] = prevIndx;
                }
            }
            if (dp[indx] > maxi){
                maxi=  dp[indx];
                maxIndx = indx;
            }
        }
        
        vector<int> ans;
        while (hash[maxIndx] != maxIndx){
            ans.push_back(arr[maxIndx]);
            maxIndx = hash[maxIndx];
        }
        ans.push_back(arr[maxIndx]);
        reverse(ans.begin(), ans.end());
        for (auto it : ans) cout << it << " ";
        return maxi;
    }
    int binarySearch(vector<int>& arr){
        int maxi = 1;
        vector<int> dp(n, 1);
        vector<int> temp;
        temp.push_back(arr[0]);
        for (int i=1; i<n; i++){
            if (arr[i] > temp.back()){
                temp.push_back(arr[i]);
                dp[i] = temp.size();
            }
            else{
                int indx = lower_bound(temp.begin(), temp.end(), arr[i]) - temp.begin();
                temp[indx] = arr[i];
                dp[i] = indx + 1;
            }
            maxi = max(maxi, (int)temp.size());
        }
        return maxi;
    }
    int lengthOfLIS(vector<int>& arr) {
        n = arr.size();
        // return binarySearch(arr);
        return tabulation1(arr);
    }
};