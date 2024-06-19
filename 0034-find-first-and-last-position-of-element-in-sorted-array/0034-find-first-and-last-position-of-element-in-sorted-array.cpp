class Solution {
public:
    int n;
    int firstOccurence(vector<int>& arr, int target){
        int low = 0, high = n-1;
        while (low <= high){
            int mid = low + (high-low)/2;
            if (arr[mid] >= target) high = mid - 1;
            else low = mid + 1;
        }
        return high+1;
    }
    int lastOccurence(vector<int>& arr, int target){
        int low = 0, high = n-1;
        while (low <= high){
            int mid = low + (high-low)/2;
            if (arr[mid] <= target) low = mid + 1;
            else high = mid - 1;
        }
        return low - 1;
    }
    vector<int> searchRange(vector<int>& arr, int target) {
        n = arr.size();
        int first = firstOccurence(arr, target);
        if (first == n || arr[first]!=target) return {-1,-1};
        int second = lastOccurence(arr, target);   
        return {first, second};
    }
};