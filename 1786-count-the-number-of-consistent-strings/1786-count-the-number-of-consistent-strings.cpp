class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_map<char, int> myMap;
        for (auto it : allowed){
            myMap[it]++;
        }
        int realCnt = myMap.size(), ans = 0;
        for (auto it : words){
            bool flag = 0;
            for (auto ch : it){
                if (myMap.find(ch) == myMap.end()){
                    flag = 1;
                    break;
                }
            }
            if (!flag) ans++;
        }
        return ans;
    }
};