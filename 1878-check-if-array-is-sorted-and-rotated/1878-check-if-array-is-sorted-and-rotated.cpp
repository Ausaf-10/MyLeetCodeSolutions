class Solution {
public:
    bool check(vector<int>& arr) {
        int n = arr.size(), peak = 0;
        for (int i=1; i<n; i++){
            if (arr[i] < arr[i-1]) peak++;
        }
        if(peak == 0) return true;
        if (peak == 1 && arr[0] >= arr[n-1]) return true;
        return false;
    }
};