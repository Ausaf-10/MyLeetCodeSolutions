using ll = long long int;
class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        if (arr.size() == 1) return arr[0];
        map<ll,ll> mp;
        for (int i=0; i<arr.size(); i++){
            mp[arr[i]]++;
        }
        float maxi = (25.0/100)*(arr.size());
        cout << maxi;
        for (auto it : mp){
            ll cnt = it.second;
            if (cnt > (int)maxi){
                return it.first;
            }
        }
        return 0;
    }
};