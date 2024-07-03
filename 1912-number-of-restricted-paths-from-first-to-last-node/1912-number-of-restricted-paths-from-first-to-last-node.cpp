const int mod = 1e9+7;
using ll = long long int;
class Solution {
public:
    int n;
    void dijkstra(vector<ll> &distance, ll src, vector<vector<ll>> adj[]){
        priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> pq;
        pq.push({0,src}); distance[src] = 0;
        while (!pq.empty()){
            auto topNode = pq.top(); pq.pop();
            ll dis = topNode.first, node = topNode.second;
            for (auto it : adj[node]){
                ll neighbor = it[0], wt = it[1];
                if (dis + wt < distance[neighbor]){
                    distance[neighbor] = dis + wt;
                    pq.push({dis + wt,neighbor});
                } 
            } 
        }
        return ;
    }
    ll memoization(ll node, vector<vector<ll>> adj[], vector<ll> &distance, vector<ll>& dp){
        if (node == n) return 1;
        if (dp[node]!=-1) return dp[node];
        ll ans = 0;
        for (auto it : adj[node]){
            if (distance[it[0]] < distance[node]){
                ans = (ans + memoization(it[0], adj, distance, dp))%mod;
            }
        }
        return dp[node] = ans;
    }
    ll countRestrictedPaths(int N, vector<vector<int>>& edges) {
        n = N;
        vector<vector<ll>> adj[n+1];
        for (auto it : edges){
            ll u = it[0], v = it[1], wt = it[2];
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
        vector<ll> distance(n+1, 1e18), dp(n+1, -1);
        dijkstra(distance, n, adj);
        return memoization(1, adj, distance, dp);

    }
};