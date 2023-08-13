class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
       int first = -1, second = -1;

       int n = nums.size();
       int low = 0, high = n-1;
       while (low <= high){
           int mid = low + (high - low) / 2;
            if (nums[mid] == target){
               first = mid, high = mid - 1;
            }
            else if (nums[mid] > target) high = mid - 1;
            else low = mid + 1;
        }

       low = 0, high = n-1;
       while (low <= high){
           int mid = low + (high - low) / 2;
            if (nums[mid] == target){
               second = mid, low = mid + 1;
            }
            else if (nums[mid] < target) low = mid + 1;
            else high = mid - 1;
        }

        if (first == -1) return {-1,-1};

        return {first, second};
    }
};