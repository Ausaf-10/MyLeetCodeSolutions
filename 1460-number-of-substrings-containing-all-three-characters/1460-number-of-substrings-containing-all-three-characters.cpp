class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size(), ans = 0;
        vector<int> hash(3,-1);
        for (int i=0; i<n; i++){
            hash[s[i]-'a'] = i;
            if (hash[0]==-1 || hash[1]==-1 || hash[2]==-1) continue;
            int indx = min(hash[0], min(hash[1], hash[2]));
            ans += 1 + indx;
        }
        return ans;
    }
};