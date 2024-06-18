class Solution {
public:
    bool checkSubarraySum(vector<int>& arr, int k) {
        unordered_map<int,int> mp;
        int sum = 0, cnt = 0;
        int n = arr.size();
        for (int i=0; i<n; i++){
            sum+=arr[i];
            int rem = sum % k;
            if (rem == 0){
                if (i + 1 >= 2) return true;
            }
            if (mp.find(rem) != mp.end()){
                int len = i - mp[rem];
                if (len >= 2) return true;
            }
            if (mp.find(rem) == mp.end())
                mp[rem] = i;
        }
        return false;
    }
};