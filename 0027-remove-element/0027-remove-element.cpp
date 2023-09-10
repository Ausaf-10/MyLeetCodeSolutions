class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i;
        for (i=0; i<nums.size(); i++){
            if (nums[i] == val) break;
        }
        int j=i+1;
        while (j < nums.size()){
            if (nums[i] == nums[j]){
                j++;
                
            }
            else{
                swap(nums[i],nums[j]);
                i++,j++;
            }
        }
        return i;
    }
};