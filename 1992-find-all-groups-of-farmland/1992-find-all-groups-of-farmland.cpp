class Solution {
public:
    int n,m;
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        n = land.size(), m = land[0].size();
        vector<vector<int>> ans;
        for (int row=0; row<n; row++){
            for (int col=0; col<m; col++){
                if (!land[row][col]) continue;
                int r2 = row, c2 = col;
                while (c2 < m && land[row][c2]) c2++;
                while (r2 < n && land[r2][col]) r2++;

                r2 = r2 == 0 ? 0 : r2-1;
                c2 = c2 == 0 ? 0 : c2-1;

                ans.push_back({row,col,r2,c2});

                for (int i=row; i<=r2; i++){
                    for (int j=col; j<=c2; j++){
                        land[i][j] = 0;
                    }
                }
            }
        }
        return ans;
    }
};