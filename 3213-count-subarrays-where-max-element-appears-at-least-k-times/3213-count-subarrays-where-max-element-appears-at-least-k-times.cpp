using ll = long long int;
class Solution {
public:
    ll atMost(vector<int>& arr, int k){
        ll n = arr.size(), i = 0, j = 0, cnt = 0, freq = 0;
        ll maxi = *max_element(arr.begin(), arr.end());
        while (j < n){
            if (arr[j] == maxi) freq++;
            while (freq > k){
                if (arr[i] == maxi) freq--;
                i++;
            }
            cnt += j-i+1;
            j++;
        }
        return cnt;
    }
    long long countSubarrays(vector<int>& arr, int k) {
        int maxi = *max_element(arr.begin(), arr.end());
        ll n = arr.size();
        unordered_map<int, int> mp;
        for (auto it : arr) mp[it]++;
        int freq = mp[maxi];
        return atMost(arr, freq) - atMost(arr, k-1);
    }
};