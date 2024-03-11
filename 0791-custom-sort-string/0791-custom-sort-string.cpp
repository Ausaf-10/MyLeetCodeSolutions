class Solution {
public:
    string customSortString(string order, string s) {
        string res;
        unordered_map<char, int> mp;
        for (auto it : s) mp[it]++;
        for (int i=0; i<order.size(); i++){
            if (mp.find(order[i]) != mp.end()){
                int freq = mp[order[i]];
                for (int j=0;j<freq; j++){
                    res.push_back(order[i]);
                }
                mp.erase(order[i]);
            }
        } 
        for (int i=0; i<s.size(); i++){
            if (mp.find(s[i]) != mp.end()){
                int freq = mp[s[i]];
                for (int j=0;j<freq; j++){
                    res.push_back(s[i]);
                }
                mp.erase(s[i]);
            }
        }
        return res;
    }
};