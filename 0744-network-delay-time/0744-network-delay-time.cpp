class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int src) {
        vector<pair<int,int>> adj[n+1];
        for (auto it : times){
            int u = it[0], v = it[1], wt = it[2];
            adj[u].push_back({v,wt});
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<int> distance(n+1, 1e9);
        distance[src] = 0; pq.push({0,src});
        while (!pq.empty()){
            auto top = pq.top(); pq.pop();
            int dis = top.first, node = top.second;
            for (auto it : adj[node]){
                int neighbor = it.first, wt = it.second;
                if (distance[neighbor] > dis + wt){
                    distance[neighbor] = dis + wt;
                    pq.push({dis + wt, neighbor});
                }
            }
        }
        int maxi = 0;
        for (int i=1; i<=n; i++){
            if (distance[i] == 1e9) return -1;
            maxi = max(maxi, distance[i]);
        }
        return maxi;
    }
};