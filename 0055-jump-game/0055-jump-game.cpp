class Solution {
public:
    bool canJump(vector<int>& nums) {
       int n = nums.size(), maxi = 0;
       for (int i=0; i<n; i++){
           if (i > maxi) return false;
           maxi = max(maxi, nums[i] + i);
       }
       return true;
    }
};