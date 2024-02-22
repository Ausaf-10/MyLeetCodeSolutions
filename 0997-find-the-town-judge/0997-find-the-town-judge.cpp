class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> adj[n+1];
        for (auto it : trust){
            int u = it[0], v = it[1];
            adj[u].push_back(v);
        }
        int town = -1;
        for (int i=1; i<=n; i++){
            if (adj[i].size() == 0){
                town = i;
                break;
            }
        }
        for (int i=1; i<=n; i++){
            if (i == town) continue;
            bool flag = 0;
            for (auto it : adj[i]){
                if (it==town){
                    flag = 1;
                }
            }
            if (!flag) return -1;
        }
        return town;
    }
};