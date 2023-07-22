class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // CREATE AN ADJACENCY LIST
        
        vector<pair<int,int>> adj[n];
        for (int i=0; i<flights.size(); i++){
            int u = flights[i][0];
            int v = flights[i][1];
            int wt = flights[i][2];
            
            adj[u].push_back({v,wt});
        }
        
        // STOPS : {NODE,DIST}
        queue<pair<int,pair<int,int>>> q;
        vector<int> dist(n,1e9);
        dist[src] = 0  ;
        q.push({0,{src,0}});
        
        while (!q.empty()){
            auto it = q.front();
            q.pop();
            
            int stop = it.first;
            int node = it.second.first;
            int dis = it.second.second;
            
            // if (stop == k + 1 && node == dst) return dis; 
            if (stop > k) continue;
            
            for (auto v: adj[node]){
                int neighbor = v.first;
                int wt = v.second;
                if ( wt + dis  < dist[neighbor] && stop<=k){
                    dist[neighbor] = wt + dis;
                    q.push({stop+1,{neighbor,wt + dis}});
                }
            }
        }
        
        if (dist[dst] == 1e9) return -1;
        return dist[dst];
        
    }
};