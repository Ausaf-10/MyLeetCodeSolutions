using ll = long long int;
class Solution {
public:
    long long largestPerimeter(vector<int>& arr) {
        ll s = 0, n = arr.size(), i = n-1;
        sort(arr.begin(), arr.end());
        vector<ll> preSum(n,0);
        preSum[0] = arr[0];
        for (int i=1; i<n; i++){
            preSum[i] = preSum[i-1] + arr[i];
        }
        while (i >= 2){
            ll remSum = preSum[i] - arr[i];
            if (remSum > arr[i]) return preSum[i];
            i--;
        }
        return -1;
    }
};