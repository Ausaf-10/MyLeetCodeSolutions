class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& arr, int k) {
        int n = arr.size(), i = 0, j = 0, cnt = 0, prod = 1;
        if (k <= 1) return 0;
        while (j < n){
            prod*=arr[j];
            while (prod >= k){
                prod/=arr[i];
                i++;
            }
            cnt += (j-i+1);
            j++;
        }
        return cnt;
    }
};