class Solution {
public:
    int n;
    int atMost(string& arr, int k){
        if (k < 0) return 0;
        int i=0,j=0,cnt=0;
        unordered_map<char,int> mp;
        while (j < n){
            mp[arr[j]]++;
            while (mp.size() > k){
                mp[arr[i]]--;
                if (mp[arr[i]] == 0) mp.erase(arr[i]);
                i++;
            }
            if(mp.size() <= k){
                cnt+=(j-i+1);
            } 
            j++;
        }
        return cnt;
    }
    int numberOfSubstrings(string s) {
        n = s.size();
        return n*1ll*(n+1)/2 - atMost(s,2);
    }
};