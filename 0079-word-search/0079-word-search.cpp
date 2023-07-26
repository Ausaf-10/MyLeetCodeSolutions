class Solution {
public:

    bool isValid(vector<vector<char>>& board, int row, int col, int k,
     string &word, vector<vector<int>>& vis){
        if (row>=0 && row<board.size() && col>=0 && col<board[0].size() && board[row][col] == word[k] && vis[row][col] == 0){
            vis[row][col] = 1;
            return true;
        }
        return false;
    }

    bool solve(vector<vector<char>>& board, int row, int col, int k,
     string &word, vector<vector<int>>& vis){
        
        if (k == word.size()) return true;

        int delrow[4] = {-1,0,1,0};
        int delcol[4] = {0,1,0,-1};
        for (int i=0; i<4; i++){
            int nrow = delrow[i] + row;
            int ncol = delcol[i] + col;
            if (isValid(board, nrow, ncol, k, word, vis)){
                if (solve(board, nrow, ncol, k+1, word, vis) == true) return true;
            }

        }
        vis[row][col] = 0;
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();

        vector<vector<int>> vis(n,vector<int>(m,0));

        int k = 1;

        for (int i=0; i<n; i++){
            for (int j=0; j<m; j++){
                if (board[i][j] == word[0]){
                    vis[i][j] = 1;
                    if (solve(board,i,j,k,word,vis) == true){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};