class Solution {
public:
    int findNonMinOrMax(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        if (n <= 2) return -1;
        return arr[1];
    }
};