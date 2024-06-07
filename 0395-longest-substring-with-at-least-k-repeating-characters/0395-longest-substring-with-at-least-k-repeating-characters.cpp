class Solution {
public:
    bool countFunction(string& arr, unordered_map<char,int>&mp, int k){
        for (auto it : mp){
            if (it.second < k) return false;
        }
        return true;
    }
    int longestSubstring(string arr, int k) {
        int n=arr.size(),maxi = 0;
        for (int i=0; i<n; i++){
            unordered_map<char,int> mp;
            for (int j=i; j<n; j++){
                mp[arr[j]]++;
                if (countFunction(arr, mp, k)) maxi = max(maxi, j-i+1);
            }
        }
        return maxi;
    }

};