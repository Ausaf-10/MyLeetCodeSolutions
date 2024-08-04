class neighborSum {
public:
    int n,m;
    vector<vector<int>> mat;
    neighborSum(vector<vector<int>>& grid) {
        mat = grid;
        n = grid.size(), m = grid[0].size();
    }
    
    bool isValid(int row, int col){
        if (row >= 0 && row < n && col >= 0 && col<m) return true;
        return false;
    }
    
    int adjacentSum(int value) {
        vector<vector<int>>directions = {{-1,0}, {0, 1}, {1, 0}, {0,-1}};
        int sum = 0;
        for (int i=0; i<n; i++){
            for (int j=0; j<m; j++){
                if (mat[i][j] == value){
                    for (auto it : directions){
                        int nrow = i + it[0], ncol = j + it[1];
                        if (isValid(nrow, ncol)){
                            sum += mat[nrow][ncol];
                        }
                    }
                    break;
                }
            }
        }
        return sum;
    }
    
    int diagonalSum(int value) {
        vector<vector<int>>directions = {{-1,-1}, {-1, 1}, {1, -1}, {1,1}};
        int sum = 0;
        for (int i=0; i<n; i++){
            for (int j=0; j<m; j++){
                if (mat[i][j] == value){
                    for (auto it : directions){
                        int nrow = i + it[0], ncol = j + it[1];
                        if (isValid(nrow, ncol)){
                            sum += mat[nrow][ncol];
                        }
                    }
                    break;
                }
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