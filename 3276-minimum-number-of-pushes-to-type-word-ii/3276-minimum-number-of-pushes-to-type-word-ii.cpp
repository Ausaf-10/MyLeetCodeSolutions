class Solution {
public:
    int minimumPushes(string word) {
        unordered_map<char, int> freqMap, indxMap;
        unordered_map<int, string> keyMap;
        for (auto it : word) freqMap[it]++;
        priority_queue<pair<int, char>> pq;
        for (auto it : freqMap){
            pq.push({it.second, it.first});
        }
        int no = 2;
        while (!pq.empty()){
            auto it = pq.top(); pq.pop();
            char ch = it.second;
            keyMap[no].push_back(ch);
            indxMap[ch] = keyMap[no].size();
            no++;
            if (no == 10) no = 2;
        }
        int ans = 0;
        for (auto ch : word){
            ans += indxMap[ch];
        }
        return ans;
    }
};