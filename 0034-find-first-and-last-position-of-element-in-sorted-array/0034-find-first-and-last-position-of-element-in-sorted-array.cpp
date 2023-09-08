class Solution {
public:
    int n;
    int lowerBound(vector<int> arr, int x) {
	// Write your code here
        int low = 0, high = n-1;
        int ans = n;
        while (low <= high){
            int mid = low + (high - low)/2;
            if (arr[mid] >= x){
                high = mid - 1;
                ans = mid;
            }
            else low = mid + 1;
        }
        return ans;
    }
    int upperBound(vector<int> &arr, int x){
        // Write your code here.	
        int low = 0, high = n-1;
        int ans = n;
        while (low <= high){
            int mid = low + (high - low)/2;
            if (arr[mid] > x){
                high = mid - 1;
                ans = mid;
            }
            else low = mid + 1;
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        n = nums.size();
        int lb = lowerBound(nums, target); 
        int ub = upperBound(nums, target);

        if (lb == n || nums[lb]!= target) return {-1,-1};

        return {lb, ub-1}; 
    }
};