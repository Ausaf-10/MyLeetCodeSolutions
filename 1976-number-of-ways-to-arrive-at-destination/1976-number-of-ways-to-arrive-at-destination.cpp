class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<long long,long long>> adj[n];
        for (int i=0; i<roads.size(); i++){
            int u = roads[i][0];
            int v = roads[i][1];
            int wt = roads[i][2];
            
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
        
        long long mod = 1e9+7;
        
        priority_queue<pair<long long,long long>,
        vector<pair<long long,long long>>,greater<pair<long long,long long>>> minHeap;
        minHeap.push({0,0}); // DIST,NODE
        
        vector<long long> dist(n,LONG_MAX), ways(n,0);
        dist[0] = 0;
        ways[0] = 1;    
        
        while (!minHeap.empty()){
            long long dis = minHeap.top().first;
            long long node = minHeap.top().second;
            minHeap.pop();
            
            for (auto v : adj[node]){
                long long neighbor = v.first;
                long long wt = v.second;
                
                if (dist[neighbor] > wt + dis){
                    dist[neighbor] = wt + dis;
                    minHeap.push({wt + dis,neighbor});
                    ways[neighbor]=(ways[node])%mod;
                }
                
                else if (dist[neighbor] ==  wt + dis) {
                    ways[neighbor]=(ways[neighbor]+ways[node])%mod;
                }
            }
            
        }
        
        return (ways[n-1])%mod;
            
    }
};