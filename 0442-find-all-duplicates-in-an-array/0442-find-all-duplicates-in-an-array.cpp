class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        for (int i=0; i<nums.size(); i++){
            int number = abs(nums[i]);
            int indx = number - 1;
            if (nums[indx] < 0){
                ans.push_back(number);
            }
            else nums[indx]*=-1;
        }
        return ans;
    }
};