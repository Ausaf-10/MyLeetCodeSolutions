class Solution {
public:
    int searchInsert(vector<int>& arr, int target) {
        int n = arr.size();
        int ans = n, low = 0, high = n - 1;

        while (low <= high){
            int mid = low + (high - low)/2;
            if (arr[mid] >= target){
                ans = mid , high = mid - 1;
            }
            else low = mid + 1;
        }

        return ans;
    }
};