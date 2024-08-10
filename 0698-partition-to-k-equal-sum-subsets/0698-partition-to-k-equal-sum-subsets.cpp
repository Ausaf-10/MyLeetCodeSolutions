class Solution {
public:
    int n, k, reqSum;
    bool recursion(int indx, int var_sum, int buckets, vector<int>& arr, vector<int> &vis){
        if (var_sum == 0) return recursion(0, reqSum, buckets+1, arr, vis);
        if (buckets == k) return true;
        if (indx >= n) return false;
        for (int i=indx; i<n; i++){
            if (vis[i]) continue;
            if (arr[i] > var_sum) break;
            vis[i] = 1;
            if (recursion(i+1, var_sum - arr[i], buckets, arr, vis)) return true;
            vis[i] = 0;
        }
        return false;
    }
    bool canPartitionKSubsets(vector<int>& arr, int K) {
        int totSum = accumulate(arr.begin(), arr.end(), 0);
        n = arr.size(), k = K, reqSum = totSum / k;
        if (totSum % k != 0) return false;
        vector<int> vis(n, 0);
        sort(arr.begin(), arr.end());
        return recursion(0, reqSum, 0, arr, vis);
    }
};