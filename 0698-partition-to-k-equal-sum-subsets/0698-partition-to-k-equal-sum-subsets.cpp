class Solution {
public:
    int n, k, reqSum;
    bool recursion(int indx, int var_sum, int buckets, vector<int>& arr, vector<int> &vis){
        if (var_sum == 0) return recursion(0, reqSum, buckets+1, arr, vis);
        if (buckets == k) return true;
        if (indx >= n) return false;
        if (vis[indx]) return recursion(indx+1, var_sum, buckets, arr, vis);
        else{
            bool op1 = false;
            if (arr[indx] <= var_sum){
                vis[indx] = 1;
                op1 = recursion(indx+1, var_sum - arr[indx], buckets, arr, vis);
                vis[indx] = 0;
            }
            bool op2 = recursion(indx+1, var_sum, buckets, arr, vis);
            return op1 || op2; 
        }
    }
    bool canPartitionKSubsets(vector<int>& arr, int K) {
        int totSum = accumulate(arr.begin(), arr.end(), 0);
        n = arr.size(), k = K, reqSum = totSum / k;
        if (totSum % k != 0) return false;
        vector<int> vis(n, 0);
        return recursion(0, reqSum, 0, arr, vis);
    }
};