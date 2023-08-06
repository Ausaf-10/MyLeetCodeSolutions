class Solution {
public:
    void bfs(int node, vector<int>& vis, vector<int> adj[]){
        queue<int> q;
        q.push(node);
        vis[node]=1;

        while (!q.empty()){
            int node = q.front();
            q.pop();

            for (auto it : adj[node]){
                if (!vis[it]){
                    q.push(it);
                    vis[it] = 1;
                }
            }
        }

        return ;
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
       
        vector<int> adj[n];
        for (int i=0; i<n; i++){
            for (int j=0; j<n; j++){
                if (isConnected[i][j] == 1 && i!=j){
                    adj[i].push_back(j);
                }
            }
        }

        int cnt = 0;
        vector<int> vis(n,0);
        for (int i=0; i<n; i++){
            if (!vis[i]){
                bfs(i,vis,adj);
                cnt++;
            }
        }

        return cnt;
    }

};