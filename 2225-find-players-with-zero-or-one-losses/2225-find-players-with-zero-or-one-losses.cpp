class Solution {
public:

    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int,int> loserMap;
        vector<vector<int>> ans(2);
        // 0th indx -> ALL WINNERS ARE THERE -> NOT LOST ANY MATCHES
        // 1st indx -> LOST EXACTLY ONE MATCHE

        for (int i=0; i<matches.size(); i++){
            int loser = matches[i][1];
            loserMap[loser]++;
        }

        for (int i=0; i<matches.size(); i++){
            int winner = matches[i][0];
            if (loserMap.find(winner) == loserMap.end()){
                loserMap[winner] = 0;
            }
        }

        for (auto it : loserMap){
            int freq = it.second;
            if (freq == 1) ans[1].push_back(it.first);
            if (freq == 0) ans[0].push_back(it.first);
        }

        return ans;
    }
};