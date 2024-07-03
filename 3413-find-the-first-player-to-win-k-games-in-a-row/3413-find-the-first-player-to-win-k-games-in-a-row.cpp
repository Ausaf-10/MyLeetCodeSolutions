class Solution {
public:
    int findWinningPlayer(vector<int>& arr, int k) {
        int prev = 0, n = arr.size(), cnt = 0, i;
        for (i=1; i<n; i++){
            if (arr[i] > arr[prev]){
                cnt = 0;
                prev = i;
            }
            if (++cnt == k) return prev;
        }
        return prev;
    }
};