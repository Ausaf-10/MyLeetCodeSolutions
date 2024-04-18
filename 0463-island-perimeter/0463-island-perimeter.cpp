
class Solution {
public:
    int n,m;
    bool valid(int row, int col, vector<vector<int>>& grid){
        if (row>=0 && row<n && col>=0 && col<m && grid[row][col]) return true;
        return false;
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();
        int ans = 0;
        for (int row=0; row<n; row++){
            for (int col=0; col<m; col++){
                if (grid[row][col] == 1){
                    int count = 0;
                    int delrow[4] = {-1, 0, 1, 0};
                    int delcol[4] = {0, 1, 0, -1};
                    for (int i=0; i<4; i++){
                        int nrow = delrow[i] + row;
                        int ncol = delcol[i] + col;
                        if (valid(nrow, ncol, grid)){
                            count++;
                        }
                        
                    }
                    ans+=(4-count);
                }
            }
        }
        return ans;
    }
};