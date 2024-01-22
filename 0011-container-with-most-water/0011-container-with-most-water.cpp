class Solution {
public:
    int maxArea(vector<int>& arr) {
        int maxi = -1e9, n = arr.size();
        int i = 0, j = n-1;
        while (i < j){
            int mini = min(arr[i], arr[j]);
            int area = mini * (j-i);
            maxi = max(maxi, area);
            if (arr[i] <= arr[j]) i++;
            else j--;
        }
        return maxi;
    }

};