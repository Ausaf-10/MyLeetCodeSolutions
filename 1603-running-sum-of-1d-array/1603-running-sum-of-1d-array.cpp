class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefixSum(n,0);
        prefixSum[0] = nums[0];
        if (nums.size() == 1) return prefixSum;
        for (int i=1; i<n; i++){
            prefixSum[i] += prefixSum[i-1] + nums[i];
        }

        return prefixSum;
    }
};