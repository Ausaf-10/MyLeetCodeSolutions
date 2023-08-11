class Solution {
public:
    int thirdMax(vector<int>& nums) {
        // WE WILL KEEP 3 MAXIMUMS AND WILL COMPARE EACH OF THEM WHENEVER WE NEED TO UPDATE THE VALUE AND WITH THE HELP OF VARIABLES
        // ONLY WE WILL BE ABLE TO DO THIS QUESTION IN CONSTANT SPACE AND LINEAR TIME 

        if (nums.size() == 1) return nums[0]; // SIZE 1
        else if (nums.size() == 2) return max(nums[0], nums[1]);

        long m1 = LONG_MIN, m2 = LONG_MIN, m3 = LONG_MIN;
        int n = nums.size();
        for (auto it : nums){
            if (it == m1 || it == m2 || it == m3) continue; // FOR UNIQUENESS
            if (it > m1){
                m3 = m2, m2 = m1, m1 = it;
            }
            else if (it > m2){
                m3 = m2, m2 = it;
            }
            else if (it > m3){
                m3 = it;
            }
        } 

        if (m3 == LONG_MIN ) return (int)m1;
        return (int) m3; 
    }
};