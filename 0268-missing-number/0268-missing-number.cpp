class Solution {
public:
    int missingNumber(vector<int>& arr) {
        int n = arr.size();
        int xr1 = 0, xr2 = 0;
        for (int i=0; i<n; i++){
            xr1 = xr1^arr[i];
            xr2 = xr2^(i+1);
        }
        return xr1^xr2;
    }
};