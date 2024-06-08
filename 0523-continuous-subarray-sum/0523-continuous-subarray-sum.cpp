using ll = long long int;
class Solution {
public:
    bool checkSubarraySum(vector<int>& arr, int k) {
        unordered_map<ll,ll> mp;
        ll sum = 0;
        for (ll i=0; i<arr.size(); i++){
            sum+=arr[i];
            ll rem = sum % k;
            if (rem == 0){
                if (i+1>=2) return true;
            }
            if (mp.find(rem) != mp.end()){
                ll len = i- mp[rem];
                if (len >= 2) return true;
            }
            if (mp.find(rem) == mp.end()) mp[rem] = i;
        }
        return false;
    }
};