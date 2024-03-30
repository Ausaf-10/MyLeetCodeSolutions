class Solution {
public:
    int atMost(vector<int>& arr, int k){
        if (k < 0) return 0;
        int i=0,j=0,s=0,n=arr.size(),cnt = 0;
        unordered_map<int,int> mp;
        while (j < n){
            mp[arr[j]]++;
            while (mp.size() > k){
                mp[arr[i]]--;
                if (mp[arr[i]] == 0) mp.erase(arr[i]);
                i++;
            }
            if (mp.size() <= k){
                cnt += j-i+1;
            }
            j++;
        }
        return cnt;
    }
    int subarraysWithKDistinct(vector<int>& arr, int k) {
        return atMost(arr,k) - atMost(arr,k-1);
    }
};