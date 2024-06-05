class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        unordered_map<char, int> characterCount;
        int n = words.size();
        for (auto it : words){
            for (int i=0; i<it.size(); i++){
                characterCount[it[i]]++;
            }
        }
        vector<string> ans;
        for (auto &it : characterCount){
            int mini = 1e9, flag = 1, freq = it.second;
            char ch = it.first;
            for (int j=0; j<n; j++){
                unordered_map<char, int> mp;
                string str = words[j];
                for (int i=0; i<str.size(); i++) mp[str[i]]++;
                if (mp.find(ch) == mp.end()){
                    flag = 0;
                    break;
                }
                else{
                    mini = min(mini, mp[ch]);
                }
            }
            if (flag == 0) continue;
            string temp;
            temp.push_back(ch);
            for (int i=0; i<mini; i++){
                ans.push_back(temp);
            }
        }
        return ans;
    }
};