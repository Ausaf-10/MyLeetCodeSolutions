class Solution {
public:
    int missingNumber(vector<int>& arr) {
        int n = arr.size(), xr = 0;
        for (int i=0; i<arr.size(); i++){
            xr = xr^(i+1);
            xr = xr^(arr[i]);
        }
        return xr;
    }
};