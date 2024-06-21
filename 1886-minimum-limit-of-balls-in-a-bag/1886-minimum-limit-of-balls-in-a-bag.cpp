class Solution {
public:
    int n;
    bool isPossible(vector<int>& arr, int noBalls, int maxOperations){
        int reqdOperations = 0;
        for (int i=0; i<n; i++){
            reqdOperations += floor((arr[i]-1)/(double)noBalls);
        }
        if (reqdOperations <= maxOperations) return true;
        return false;
    }
    int minimumSize(vector<int>& arr, int maxOperations) {
        n = arr.size();
        int low = 1, high = *max_element(arr.begin(), arr.end());
        while (low <= high){
            int mid = low + (high - low)/2;
            if (isPossible(arr, mid, maxOperations)) high = mid - 1;
            else low = mid + 1;
        }
        return low;
    }
};