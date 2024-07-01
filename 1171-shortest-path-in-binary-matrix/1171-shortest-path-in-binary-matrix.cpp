class Solution {
public:
    int n,m;
    bool isValid(vector<vector<int>> &grid, int row, int col){
        if (row>=0 && row<n && col>=0 && col<m && grid[row][col] == 0) return true;
        return false;
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();

        vector<vector<int>> distance(n,vector<int> (m,1e9));
        if (grid[0][0] == 1) return -1;
        distance[0][0]=1;

        queue<pair<int,pair<int,int>>> q;
        q.push({1,{0,0}});
        while (!q.empty()){
            auto node = q.front(); q.pop();
            int dis = node.first, row = node.second.first, col = node.second.second;
            if (row == n-1 && col == m-1) return dis;

            for (int delrow=-1; delrow<=1; delrow++){
                for (int delcol=-1; delcol<=1; delcol++){
                    int nrow = row + delrow;
                    int ncol = col + delcol;
                    if (isValid(grid,nrow,ncol)){
                        if (distance[nrow][ncol] > dis + 1){
                            distance[nrow][ncol] = dis + 1;
                            q.push({dis+1,{nrow,ncol}});
                        }
                    }
                }
            }
        }
        return -1;
    }
};