class Solution {
public:
    int findLengthOfLCIS(vector<int>& arr) {
        int n = arr.size(), maxi = 1, start = 0;
        vector<int> dp(n, 1);
        for (int indx = 1; indx<n; indx++){
            if (arr[indx-1] >= arr[indx]) start = indx;
            maxi = max(maxi, indx-start+1);
        }
        return maxi;
    }
};