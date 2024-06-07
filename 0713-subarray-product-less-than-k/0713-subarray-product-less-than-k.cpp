using ll = long long int;
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& arr, int k) {
        if (k == 0) return 0;
        ll n = arr.size(), i = 0, j = 0, prod = 1, cnt = 0;
        while (j < n){
            prod*=arr[j];
            while (i<=j && prod >= k){
                prod/=arr[i];
                i++;
            }
            cnt+=j-i+1;
            j++;
        }
        return int(cnt);
    }
};