class Solution {
public:
    int n,m;
    vector<vector<int>> directions = {{-1,0},{0,1},{1,0},{0,-1}};
    bool solve(vector<vector<char>>& board, string& word, int indx, int i, int j, vector<vector<int>>& vis){
        if (indx == word.size()) return true;
        if (i >= n || j>=m || i < 0 || j < 0 || board[i][j] != word[indx] || vis[i][j]) return false;

        vis[i][j] = 1;
        for (int dr=0; dr<4; dr++){
            int nrow = directions[dr][0] + i;
            int ncol = directions[dr][1] + j;
                if (solve(board, word, indx+1, nrow, ncol, vis)) return true;
        }
        
        vis[i][j] = 0;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        n = board.size(), m = board[0].size();
        vector<vector<int>> vis (n, vector<int>(m,0));
        for (int i=0; i<n; i++){
            for (int j=0; j<m; j++){
                if (board[i][j] == word[0]){
                    if (solve(board, word, 0, i, j, vis)) return true;
                }
            }
        }
        return false;
    }
};