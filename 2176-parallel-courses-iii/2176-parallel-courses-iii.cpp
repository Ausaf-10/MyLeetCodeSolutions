class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& edges, vector<int>& time) {
        vector<int> adj[n+1];
        for (auto it : edges){
            int u = it[0], v = it[1];
            adj[u].push_back(v);
        }
        vector<int> indegree(n+1,0);
        for (int i=1; i<=n; i++){
            for (auto it : adj[i]){
                indegree[it]++;
            }
        }
        vector<int> distance(n+1,0);
        queue<int> q; 
        for (int i=1; i<=n; i++){
            if (!indegree[i]){
                distance[i] = time[i-1];
                q.push(i);
            }
        }
        while (!q.empty()){
            int node = q.front(); q.pop();
            for (auto it : adj[node]){
                indegree[it]--;
                distance[it] = max(distance[it], distance[node] + time[it-1]);
                if (!indegree[it]){
                    q.push(it);
                } 
            }
        }
        int maxi = 0;
        for (auto it : distance) maxi = max(maxi, it);
        return maxi;
    }
};