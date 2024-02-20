class Solution {
public:
    int missingNumber(vector<int>& arr) {
        int n = arr.size();
        int xr1 = 0, xr2 = 0;
        for (int number : arr){
            xr1 = xr1^number;
        }
        for (int i=0; i<=n; i++){
            xr2 = xr2^i;
        }
        return xr1^xr2;
    }
};