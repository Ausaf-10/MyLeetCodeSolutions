class Solution {
public:
    bool isValid(vector<vector<int>>& grid, int row, int col, int n, int m){
        if (row>=0 && row<n && col>=0 && col<m ) return true;
        return false;
    }
    int minimumEffortPath(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> dis(n,vector<int>(m,1e9));
        dis[0][0] = 0;

        priority_queue<pair<int,pair<int,int>>,
        vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> minHeap;
        minHeap.push({0,{0,0}});

        while (!minHeap.empty()){
            int diff = minHeap.top().first;
            int row = minHeap.top().second.first;
            int col = minHeap.top().second.second;

            if (row == n-1 && col == m-1 ) return diff; 

            minHeap.pop();

            int delrow[4] = {-1,0,1,0};
            int delcol[4] = {0,1,0,-1};
            for (int i=0; i<4; i++){
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];
                
                if (isValid(grid,nrow,ncol,n,m)){
                    int newEffort = max(diff,abs(grid[row][col] - grid[nrow][ncol]));
                    if (newEffort < dis[nrow][ncol]){
                        dis[nrow][ncol] = newEffort;
                        minHeap.push({newEffort,{nrow,ncol}});
                    }
                }
            }
        }

        return 0;
    }
};