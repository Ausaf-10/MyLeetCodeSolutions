class Solution {
public:
    int numOfMinutes(int V, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<int> adj[V];
        for (int i=0; i<V; i++){
            if (manager[i] == -1) continue;
            adj[manager[i]].push_back(i);
        }

        vector<int> vis(V,0);
        vis[headID] = 1;

        queue<pair<int,int>> q; q.push({headID,0});
        int t = 0, maxi = 0;

        while (!q.empty()){
            int size = q.size();
            for (int i=0; i<size; i++){
                int node = q.front().first, tym = q.front().second;
                maxi = max(maxi, tym);
                q.pop();

                for (auto neighbor : adj[node]){
                    if (!vis[neighbor]){
                        q.push({neighbor,informTime[node] + tym});
                        vis[neighbor] = 1;
                    }
                }

            }
        }

        return maxi;
    }
};