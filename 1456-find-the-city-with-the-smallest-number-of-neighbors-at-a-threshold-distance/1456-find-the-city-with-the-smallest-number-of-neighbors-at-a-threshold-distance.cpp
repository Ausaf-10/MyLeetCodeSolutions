class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dist(n, vector<int>(n,1e9));
        for (auto it : edges){
            int u = it[0], v = it[1], wt = it[2];
            dist[u][v] = dist[v][u] = wt;            
        }
        for (int i=0; i<n; i++) dist[i][i] = 0;
        for (int k=0; k<n; k++){
            for (int i=0; i<n; i++){
                for (int j=0; j<n; j++){
                    if (i == j || dist[i][k] == 1e9 || dist[k][j] == 1e9) continue;
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }

        int minCities = 1e9, indx = -1;
        for (int i=0; i<n; i++){
            int cnt = 0;
            for (int j=0; j<n; j++){
                if (i!=j && dist[i][j] <= distanceThreshold){
                    cnt++;
                }
            }
            if (cnt <= minCities){
                minCities = cnt;
                indx = i;
            }
        }
        return indx;
    }
};