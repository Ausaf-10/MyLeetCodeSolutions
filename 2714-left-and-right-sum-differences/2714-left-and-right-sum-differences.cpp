class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        
        int rsum=0, lsum = 0;
        for (int i=0; i<n; i++ ) rsum+=nums[i];
        
        for (int i=n-1; i>=0; i--){
            lsum+=nums[i];
            ans[i] = abs(rsum-lsum);
            rsum-=nums[i];
        }

        return ans;
    }
};