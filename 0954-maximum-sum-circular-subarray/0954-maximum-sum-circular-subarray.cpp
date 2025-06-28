class Solution {
public:
    int n;
    int kadaneMax(vector<int>& arr){
        int maxi = INT_MIN, s = 0;
        for (int i=0; i<n; i++){
            s+=arr[i];
            maxi = max(maxi, s);
            if (s < 0) s = 0;
        }
        return maxi;
    }
    int kadaneMin(vector<int>& arr){
        int mini = INT_MAX, s = 0;
        for (int i=0; i<n; i++){
            s+=arr[i];
            mini = min(mini, s);
            if (s > 0) s = 0;
        }
        return mini;
    }
    int maxSubarraySumCircular(vector<int>& arr) {
        n = arr.size();
        int totSum = accumulate(arr.begin(), arr.end(), 0);
        int maxSum = kadaneMax(arr);
        int minSum = kadaneMin(arr);
        int circularSum = totSum - minSum;
        if (maxSum > 0){
            return max(maxSum, circularSum);
        }
        return maxSum;
    }
};