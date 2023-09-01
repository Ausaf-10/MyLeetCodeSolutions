class Solution {
public:
    void dfs(unordered_map<int,vector<int>> &mp, vector<int>& vis, int node){
        vis[node] = 1;
        for (auto it : mp[node]){
            if (!vis[it]){
                dfs(mp,vis,it);
            }   
        }
        return ;
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size(), m = isConnected[0].size();

        unordered_map<int,vector<int>> mp;
        for (int i=0; i<n; i++){
            for (int j=0; j<m; j++){
                if (isConnected[i][j] == 1 && i!=j){
                    mp[i].push_back(j);
                }
            }
        }
        int cnt = 0;
        vector<int> vis(n,0);
        for (int i=0; i<n; i++){
            if (!vis[i]){
                cnt++;
                dfs(mp, vis, i);
            }
        }

        return cnt;
    }
};