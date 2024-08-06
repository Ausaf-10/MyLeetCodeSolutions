class Solution {
public:
    int minimumPushes(string word) {
        unordered_map<int, string> mp;
        int k = 2, ans = 0;
        for (auto it : word){
            mp[k].push_back(it);;
            k++;
            if (k == 10) k = 2;
        }
        for (auto ch : word){
            for (auto it : mp){
                string str = it.second;
                for (int i=0; i<str.size(); i++){
                    if (ch == str[i]){
                        ans += i+1;
                        break;
                    }
                }
            }
        }
        return ans;

    }
};