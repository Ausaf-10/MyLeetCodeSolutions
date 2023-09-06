class Solution {
public:
    int kadane(vector<int>& arr){
        int n = arr.size();
        int maxSum = INT_MIN, curSum = 0;
        for (int i=0; i<n; i++){
            curSum+=arr[i];
            maxSum = max(maxSum, curSum);
            if (curSum < 0) curSum = 0;
        }
        return maxSum;
    }
    int maxSubarraySumCircular(vector<int>& arr) {
        int totSum = 0, n = arr.size();
        for (auto it : arr) totSum+=it;

        int withoutWrap = kadane(arr);

        for (int i=0; i<n; i++) arr[i]*=-1;

        int withWrap = totSum - (kadane(arr)*-1);

        if (withWrap == 0) return withoutWrap;  // when we have all negatives then this is the answer!

        return max(withoutWrap, withWrap);
    }
};