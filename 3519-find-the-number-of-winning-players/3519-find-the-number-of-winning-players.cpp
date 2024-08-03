class Solution {
public:
    int winningPlayerCount(int n, vector<vector<int>>& arr) {
        unordered_map<int, unordered_map<int,int>> mp;
        for (int i=0; i<arr.size(); i++){
            int player = arr[i][0], ball = arr[i][1];
            mp[player][ball]++;
        }
        int ans = 0;
        for (auto it : mp){
            int player = it.first;
            bool flag = 0;
            for (auto q: it.second){
                int ball = q.first, cnt = q.second;
                if (cnt > player){
                    flag = 1;
                    break;
                }
            }
            if (flag) ans++;
        }

        return ans;
    }
};