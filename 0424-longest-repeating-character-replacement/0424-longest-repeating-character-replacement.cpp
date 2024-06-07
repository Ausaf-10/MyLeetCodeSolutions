class Solution {
public:
    int longestOnes(string& arr, int k, char ch) {
        int i=0,j=0, n=arr.size(), maxi = 0, cntCharacter = 0;
        while (j < n){
            if (arr[j] != ch) cntCharacter++;
            while (cntCharacter > k && i<=j){
                if (arr[i] != ch) cntCharacter--;
                i++;
            }
            maxi = max(maxi, j-i+1);
            j++;
        }
        return maxi;
    }
    int characterReplacement(string s, int k) {
        unordered_map<char, int> mp;
        int maxi = 0;
        for (auto it : s) mp[it]++;
        for (auto it : mp){
            maxi = max(maxi, longestOnes(s, k, it.first));
        }
        return maxi;
    }
};