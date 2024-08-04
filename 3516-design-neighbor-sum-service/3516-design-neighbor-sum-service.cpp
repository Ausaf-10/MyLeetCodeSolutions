class neighborSum {
public:
    int n,m;
    vector<vector<int>> mat;
    unordered_map<int, pair<int,int>> mp;
    neighborSum(vector<vector<int>>& grid) {
        mat = grid;
        n = grid.size(), m = grid[0].size();
        for (int i=0; i<n; i++){
            for (int j=0; j<m; j++){
                mp[mat[i][j]] = {i,j};
            }
        }
    }
    
    bool isValid(int row, int col){
        if (row >= 0 && row < n && col >= 0 && col<m) return true;
        return false;
    }
    
    int adjacentSum(int value) {
        vector<vector<int>>directions = {{-1,0}, {0, 1}, {1, 0}, {0,-1}};
        int sum = 0, i = mp[value].first, j = mp[value].second;
        for (auto it : directions){
            int nrow = i + it[0], ncol = j + it[1];
            if (isValid(nrow, ncol)){
                sum += mat[nrow][ncol];
            }
        }
        return sum;
    }
    
    int diagonalSum(int value) {
        vector<vector<int>>directions = {{-1,-1}, {-1, 1}, {1, -1}, {1,1}};
        int sum = 0, i = mp[value].first, j = mp[value].second;
        for (auto it : directions){
            int nrow = i + it[0], ncol = j + it[1];
            if (isValid(nrow, ncol)){
                sum += mat[nrow][ncol];
            }
        }
        return sum;
    }
};

/**
 * Your neighborSum object will be instantiated and called as such:
 * neighborSum* obj = new neighborSum(grid);
 * int param_1 = obj->adjacentSum(value);
 * int param_2 = obj->diagonalSum(value);
 */