class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> arr = heights;
        sort(arr.begin(), arr.end());
        int i = 0, j = 0, n = arr.size(), cnt = 0;
        while (i<n && j<n){
            if (heights[i] != arr[i]) cnt++;
            i++,j++;
        }
        return cnt;
    }
};