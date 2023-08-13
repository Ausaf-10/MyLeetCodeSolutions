class Solution {
public:
    bool search(vector<int>& arr, int target) {
        int n = arr.size();
        int low = 0, high = n-1;
        while (low <= high){
            int mid = low + (high - low)/2;
            if (arr[mid] == target) return true;
            // LEFT SORTED
            else if (arr[mid] == arr[low] && arr[mid] == arr[high]){
                low = low + 1, high = high - 1;
                continue;
            }
            
            else if (arr[low] <= arr[mid]){
                if (arr[low] <= target && target<=arr[mid]){
                    high = mid - 1;
                }
                else low = mid + 1;
            }
            
            
            else {
                if (arr[mid] <= target && target<=arr[high]){
                    low = mid + 1;
                }
                else high = mid -1;
            }
        }
        return false;
    }
};