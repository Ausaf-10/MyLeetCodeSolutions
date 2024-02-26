using ll = long long int;
class Solution {
public:
    bool checkPrefix(string &str1, string& str2){
        if (str1.size() > str2.size()) return false;
        int i = 0, j = 0;
        while (i < str1.size()){
            if (str1[i++] != str2[j++]) return false;
        }
        return true;
    }
    bool checkSuffix(string &str1, string& str2){
        if (str1.size() > str2.size()) return false;
        int i = str1.size()-1, j = str2.size()-1;
        while (i >= 0){
            if (str1[i--] != str2[j--]) return false;
        }
        return true;
    }
    long long countPrefixSuffixPairs(vector<string>& words) {
        ll cnt = 0;
        unordered_map<string, int> mp;
        mp[words[0]]++;
        for (int i=1; i<words.size(); i++){
            for (auto it : mp){
                string str = it.first;
                if (str.size() > words[i].size()) continue;
                if (checkPrefix(str, words[i]) && checkSuffix(str, words[i])){
                    cnt = cnt + mp[str];
                }
            }
            mp[words[i]]++;
        }
        return cnt;
    }
};

