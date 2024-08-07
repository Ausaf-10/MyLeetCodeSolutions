// void solve(vector<string>& board, int col, int row, vector<vector<string>>& ans, int n, vector<int>& leftRow,
    // vector<int>& lowerDiagonal, vector<int>& upperDiagonal){
        
    //     if (col >= n){
    //         ans.push_back(board);
    //         return ;
    //     }
        
    //     for (int row = 0; row<n; row++){

    //         if (leftRow[row] == 0 && lowerDiagonal[row+col] == 0 && upperDiagonal[(n-1)+(col-row)] == 0){
    //             board[row][col] = 'Q';
    //             leftRow[row] = 1;
    //             lowerDiagonal[row+col] = 1;
    //             upperDiagonal[(n-1)+(col-row)] = 1;
    //             solve(board,col+1,row,ans,n,leftRow,lowerDiagonal,upperDiagonal);
    //             board[row][col] ='.';
    //             leftRow[row] = 0;
    //             lowerDiagonal[row+col] = 0;
    //             upperDiagonal[(n-1)+(col-row)] = 0;
    //         }/

    //     }

    //     return ;
    // }
class Solution {
public:
    bool isSafe(int row, int col, vector<string>& board, int n){
        int duprow = row;
        int dupcol = col;

        // CHECKING LEFT UPPER DAIGONAL
        while (row>=0 && col>=0){
            if (board[row][col] == 'Q') return false;
            row--,col--;
        }

        // CHECKING LEFT
        col = dupcol;
        row = duprow;
        while (col>=0){
            if (board[row][col] == 'Q') return false;
            col--;

        }

        // CHECKING LEFT UPPER DAIGONAL
        col = dupcol;
        row = duprow;
        while (row<n && col>=0){
            if (board[row][col] == 'Q') return false;
            row++,col--;
        }

        return true;
    }

    void solve(int col, int n, vector<string> &board, vector<vector<string>>& ans){
        if (col == n){
            ans.push_back(board);
            return ;
        }
        for (int row=0; row<n; row++){
            if (isSafe(row, col, board, n)){
                board[row][col] = 'Q';
                solve(col+1, n, board, ans);
                board[row][col] = '.';
            }
        }
        return ;
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n,'.');
        for (int i=0; i<n; i++) board[i] = s;
        solve(0, n, board, ans);
        return ans;
    }
};

        // vector<int> leftRow(n,0),lowerDiagonal(2*n-1,0),upperDiagonal(2*n-1,0);
        // solve(board,0, 0, ans, n, leftRow, lowerDiagonal, upperDiagonal);