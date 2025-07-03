class Solution {
public:
    int n,m;
    bool isPossible(vector<vector<char>>& board, string word, int row, int col, vector<vector<int>>& vis, int indx){
        if (row >= 0 && row < n && col >= 0 && col < m && !vis[row][col] && board[row][col] == word[indx]){
            
            return true;
        }
        return false;
    }
    bool solve(vector<vector<char>>& board, string word, int row, int col, vector<vector<int>>& vis, int indx){
        if (indx == word.size()) return true;
        vis[row][col] = 1;
        
        int delrow[4] = {-1,0,1,0};
        int delcol[4] = {0,1,0,-1};
        
        for (int i=0; i<4; i++){
            int nrow = delrow[i] + row;
            int ncol = delcol[i] + col;
            if (isPossible(board, word, nrow, ncol, vis, indx)){
                if (solve(board, word, nrow, ncol, vis, indx+1)) return true;
            }
        }   
        
        vis[row][col] = 0;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        n = board.size(), m = board[0].size();
        for (int i=0; i<board.size(); i++){
            for (int j=0; j<board[0].size(); j++){
                vector<vector<int>> vis(n, vector<int>(m,0));
                if (board[i][j] == word[0]){
                    // vis[i][j] = 1;
                    if (solve(board, word, i, j, vis, 1)) return true;
                }
            }
        }
        return false;
    }
};