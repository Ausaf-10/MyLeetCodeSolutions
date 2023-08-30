// SHORTEST -> 1. DIJKSTRA , 2. BFS
// 1. DIJKSTRA -> SINGLE SOURCE AND SINGLE DESTINATION -> SINGLE SOURCE SHORTEST PATH WHERE THE DESTINATION IS FIXED AS WELL!!
// 2. BFS -> WE HAVE TO APPLY THIS COZ WE DONT HAVE A SINGLE SOURCE NOR DO WE HAVE A SINGLE DESTINATION 
// IN THIS WE CAN HAVE MULTIPLE SOURCE AS WELL MULTIPLE DESTINATIONS AS WELL

//                              TRICK  -> MULTISOURCE BFS
// IN THIS WE ARE GOING TO STORE THE COORDINATES OF THE 1ST ISLAND IN A QUEUE AND THEN START BFS FROM THERE TO GET THE SECOND ISLAND AND WE WILL BE ABLE TO GET THE DISTANCE AND THAT WILL BE THE MINIMUM DISTANCE FOR SURE!!!!   

class Solution {
public:
    int n, m;
    bool isValidDFS(vector<vector<int>>& grid, int row, int col, vector<vector<int>>& vis){
        if (row>=0 && row<n && col>=0 && col<m && grid[row][col] == 1 && !vis[row][col]) return true;
        return false;
    }
    void dfs(vector<vector<int>>& grid, int row, int col, queue<pair<int,int>>& q, vector<vector<int>>& vis){
        q.push({row,col}); vis[row][col]= 1;   
        
        int delrow[4] = {-1,0,1,0};
        int delcol[4] = {0,1,0,-1};
        
        for (int i=0; i<4; i++){
            int nrow = delrow[i] + row;
            int ncol = delcol[i] + col;
            if (isValidDFS(grid, nrow, ncol, vis)){
                dfs(grid, nrow, ncol, q, vis);
            }
        }

        return ;
    }
    bool isValidBFS(vector<vector<int>>& grid, int row, int col,vector<vector<int>>& vis){
        if (row>=0 && row<n && col>=0 && col<m && !vis[row][col]) return true;
        return false;
    }
    int shortestBridge(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        n = grid.size(), m = grid[0].size();
        
        vector<vector<int>> vis (n, vector<int>(m,0));
        int startRow, startCol;
        for (int i=0; i<n; i++){
            for (int j=0; j<m; j++){
                if (grid[i][j] == 1){
                    startRow = i, startCol = j;
                    break;
                }
            }
        }
        
        dfs(grid,startRow,startCol,q,vis);

        int dis = 0;
        while (!q.empty()){
           int size = q.size();

           for (int i=0; i<size; i++){
                auto node = q.front(); q.pop();
                int row = node.first, col = node.second;

                int delrow[4] = {-1,0,1,0};
                int delcol[4] = {0,1,0,-1};
                
                for (int i=0; i<4; i++){
                    
                    int nrow = delrow[i] + row;
                    int ncol = delcol[i] + col;

                    if (isValidBFS(grid, nrow, ncol, vis)){
                        
                        if (grid[nrow][ncol] == 1) return dis;
                        
                        q.push({nrow,ncol});
                        vis[nrow][ncol] = 1;
                    }
                }
           }
           dis++;
            
        }

        return -1;
    }
};