class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> adj[n+1];
        for (auto it : trust){
            int u = it[0], v = it[1];
            adj[u].push_back(v);
        }
        int townJudge = -1;
        for (int i=1; i<=n; i++){
            if (adj[i].size() == 0){
                townJudge = i;
                break;
            }
        }
        for (int i=1; i<=n; i++){
            bool flag = 0;
            if (i == townJudge) continue;
            for (auto it : adj[i]){
                if (it == townJudge){
                    flag = 1;
                }
            }
            if (flag == 0) return -1; 
        }
        return townJudge;
    }
};