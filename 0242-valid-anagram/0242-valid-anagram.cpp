class Solution {
public:
    bool isAnagram(string pattern, string str) {
        unordered_map<char,int> mp;
        for (auto it : pattern) mp[it]++;

        int cnt = mp.size();

        for (auto ch : str){
            if (mp.find(ch)!=mp.end()){
                mp[ch]--;
                if (mp[ch] == 0) cnt--;
            }
            else return false;
        }

        if (cnt == 0) return true;
       
        return false;

    }
};