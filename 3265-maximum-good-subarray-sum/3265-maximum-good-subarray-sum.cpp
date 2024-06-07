using ll = long long int;
class Solution {
public:
    int n;
    long long maximumSubarraySum(vector<int>& arr, int k) {
        n = arr.size();
        ll maxi = LLONG_MIN;
        vector<ll> preSum(n,0);
        preSum[0] = arr[0];
        for (int i=1; i<n; i++) preSum[i] = preSum[i-1] + arr[i];
        unordered_map<ll, ll> mp;
        for (int i=0; i<n; i++){
            ll x1 = (ll)arr[i] - k, x2 = (ll)arr[i] + k;
            if (mp.find(x1) != mp.end()){
                int indx = mp[x1];
                if (indx == 0){
                    if (preSum[i] > maxi) maxi = preSum[i];
                }
                else{
                    ll sum = preSum[i] - preSum[indx-1];
                    if (sum > maxi) maxi = sum;
                }
            }
            if (mp.find(x2) != mp.end()){
                int indx = mp[x2];
                if (indx == 0){
                    if (preSum[i] > maxi) maxi = preSum[i];
                }
                else{
                    ll sum = preSum[i] - preSum[indx-1];
                    if (sum > maxi) maxi = sum;
                }
            }
            if (mp.find(arr[i]) != mp.end()){
                if (preSum[mp[arr[i]]] <= preSum[i]) continue;
            }
            mp[arr[i]] = i;
        }
        return maxi == LONG_LONG_MIN ? 0 : maxi;
    }
};