class Solution {
private:
    void dfs(int node,vector<vector<int>>& isConnected,vector<int>&vis,int V){
        vis[node] = 1;
        for (int i=0; i<V; i++){
            if (i!=node && isConnected[node][i] == 1 && !vis[i]){
                dfs(i,isConnected,vis,V);
            }
        }
        return ;
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int V = isConnected.size();
        vector<int> vis(V,0);
        int cnt=0;
        for (int i=0; i<V; i++){
            if (vis[i] == 0){
                dfs(i,isConnected,vis,V);
                cnt++;
            }
        }

        return cnt;

    }
};