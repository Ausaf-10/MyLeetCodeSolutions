class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low=0,mid=0,high=nums.size()-1;
        // (0 - LOW-1) -> 0's
        // (LOW - MID-1) -> 1's
        // (MID -HIGH) -> UNSORTED: (0/1/2)
        // (HIGH+1 - N-1) -> 2's

        while (mid <= high){
            if (nums[mid] == 0){
                swap(nums[low],nums[mid]);
                mid++,low++;
            }
            else if (nums[mid] == 1){
                mid++;
           }

           else if (nums[mid] == 2){
               swap(nums[mid],nums[high]);
               high--;
           }
        }

        return;
    }
};