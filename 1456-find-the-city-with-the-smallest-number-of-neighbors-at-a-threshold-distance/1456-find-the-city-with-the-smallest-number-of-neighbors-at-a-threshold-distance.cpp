class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        // int n = edges.size();
        vector<vector<int>> grid(n, vector<int>(n,1e8));
        for (auto it : edges){
            int u = it[0], v = it[1], wt = it[2];
            grid[u][v] = wt;
            grid[v][u] = wt;
        }

        for (int i=0; i<n; i++) grid[i][i] = 0;

        for (int k=0; k<n; k++){
            for (int i=0; i<n; i++){
                for (int j=0; j<n; j++){
                    if (grid[i][k] == 1e8 || grid[k][j] == 1e8) continue;
                    grid[i][j] = min(grid[i][j], grid[i][k] + grid[k][j]);
                }
            }
        }

        int cntMax = INT_MAX;
        int ans = -1;
        for (int i=0; i<n; i++){
            int cnt = 0;
            for (int j=0; j<n; j++){
                if (grid[i][j] <= distanceThreshold){
                    cnt++;
                }
            }
            if (cnt <= cntMax){
                cntMax = cnt;
                ans = i;
            }
        }

        return ans;

    }
};