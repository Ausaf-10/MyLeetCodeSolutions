class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_map<char, int> myMap;
        for (auto it : allowed){
            myMap[it]++;
        }
        int realCnt = myMap.size(), ans = 0;
        for (auto it : words){
            unordered_map<char, int>wordMap = myMap; 
            bool flag = 0;
            for (auto ch : it){
                if (wordMap.find(ch) == wordMap.end()){
                    flag = 1;
                    break;
                }
                else{
                    wordMap[ch]--;
                }
            }
            if (!flag) ans++;
        }
        return ans;
    }
};