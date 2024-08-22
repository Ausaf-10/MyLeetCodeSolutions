class Solution {
public:
    int findMin(vector<int>& arr) {
        int n = arr.size(), low = 0, high = n - 1;
        int mini = 1e9;
        while (low <= high){
            int mid = low + (high-low)/2;
            if (arr[low] <= arr[mid]){
                mini = min(mini, arr[low]);
                low = mid + 1;
            }
            else if (arr[mid] <= arr[high]){
                mini = min(mini, arr[mid]);
                high = mid - 1;
            }
        }
        return mini;
    }
};