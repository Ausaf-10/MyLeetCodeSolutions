class Solution {
public:
    int n;
    int countPairs(vector<int>& arr, int target) {
        n = arr.size();
        int ans = 0;
        sort(arr.begin(), arr.end());
        for (int i=0; i<n-1; i++){
            int lb = lower_bound(arr.begin()+i, arr.end(), target-arr[i]) - arr.begin();
            if (lb <= i) break;
            ans += lb-1-i;
        }
        return ans;
    }
};