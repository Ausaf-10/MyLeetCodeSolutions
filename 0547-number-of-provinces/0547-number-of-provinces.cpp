class Solution {
private:
    void bfs(int node,int n,vector<vector<int>> &grid, vector<int> &vis){
        queue<int> q;
        q.push(node);
        vis[node] = 1;
        while (!q.empty()){
            int node = q.front();
            q.pop();

            //CHECK FOR ITS NEIGHBOUR
            for (int i=0; i<n; i++){
                if (vis[i] == 0 && grid[node][i] == 1){
                    vis[i]=1;
                    q.push(i);
                }
            }
        }
        return ;
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int V = isConnected.size();
        vector<int> vis (V,0);
        int cnt=0;
        for (int i=0; i<V; i++){
            if (vis[i] == 0){
                bfs(i,V,isConnected,vis);
                cnt++;
            }
        }
        return cnt;
    }
};