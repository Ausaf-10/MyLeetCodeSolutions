using ll = long long int;
const int mod = 1e9+7;
class Solution {
public:
    int rangeSum(vector<int>& arr, int n, int left, int right) {
        vector<ll> ans;
        for(int i=0; i<n; i++){
            ll sum = 0;
            for (int j=i; j<n; j++){
                sum= (sum + arr[j])%mod;
                ans.push_back(sum);
            }
        }
        ll res = 0;
        sort(ans.begin(), ans.end());
        for (int i=left-1; i<=right-1; i++){
            res=(res + ans[i])%mod;
        }
        return res;
    }
};