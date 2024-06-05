class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<int> count(26, 0);
        for (char ch: words[0]) count[ch-'a']++;
        for (int i=1; i<words.size(); i++){
            vector<int> temp(26,0);
            for (int j=0; j<words[i].size(); j++){
                temp[words[i][j]-'a']++;
            }
            for (int j=0; j<26; j++){
                count[j] = min(count[j], temp[j]);
            }
        }
        vector<string> ans;
        for (int i=0; i<26; i++){
            if (!count[i]) continue;
            string temp;
            temp.push_back(i+'a');
            for (int j=0; j<count[i]; j++){
                ans.push_back(temp);
            }
        }
        return ans;
    }
};