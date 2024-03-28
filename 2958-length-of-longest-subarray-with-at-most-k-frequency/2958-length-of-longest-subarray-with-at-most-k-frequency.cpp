class Solution {
public:
    int maxSubarrayLength(vector<int>& arr, int k) {
        int n = arr.size(), i = 0, j = 0, maxFreq = 0, maxLen = 0;
        unordered_map<int,int> mp;
        while (j < n){
            mp[arr[j]]++;
            maxFreq = max(maxFreq, mp[arr[j]]);
            while (maxFreq > k){
                if  (maxFreq == mp[arr[i]]){
                    maxFreq--;
                }
                mp[arr[i]]--;
                if (mp[arr[i]] == 0) mp.erase(arr[i]); 
                i++;
            }
            maxLen = max(maxLen, j-i+1);
            j++;
        }
        return maxLen;
    }
};