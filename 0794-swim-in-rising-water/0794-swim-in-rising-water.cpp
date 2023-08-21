class Solution {
public:
    int n,m;
    bool isValid(vector<vector<int>>& grid, int row, int col, vector<vector<int>>& vis){
        if (row >= 0 && row < n && col>=0 && col<m && !vis[row][col]) return true;
        return false;
    }
    int swimInWater(vector<vector<int>>& grid) {
        n = grid.size(); m = grid[0].size(); 
        vector<vector<int>> vis(n, vector<int>(m,0));
        
        priority_queue<pair<int,pair<int,int>>,
        vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> minHeap;

        vis[0][0] = 1; 
        minHeap.push({grid[0][0],{0,0}}); // height -> row -> col!!!
        while (!minHeap.empty()){
            auto node = minHeap.top(); 
            minHeap.pop();

            int time = node.first;
            int row = node.second.first;
            int col = node.second.second;

            if (row == n-1 && col == m-1) return time;

            int delrow[4] = {-1,0,1,0};
            int delcol[4] = {0,1,0,-1};

            for (int i=0; i<4; i++){
                int nrow = delrow[i] + row;
                int ncol = delcol[i] + col;

                if (isValid(grid,nrow,ncol,vis)){
                    int element = max(time, grid[nrow][ncol]);
                    minHeap.push({element,{nrow,ncol}});
                    vis[nrow][ncol] = 1;
                }
            }
        }
       
        return 0;
    
    }
};