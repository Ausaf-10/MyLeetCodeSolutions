class Solution {
public:
    bool solve (vector<vector<char>>& board){
        // ITERATING THE BOARD AND CHECKING THE CELL WHETHER ITS IS EMPTY OR NOT
        for (int i=0; i<board.size(); i++){
            for (int j=0; j<board[i].size(); j++){
                
                if (board[i][j] == '.'){
                    // NOW WE HAVE GOT THE EMPTY CELL AND NOW WE ARE GOING TO PUT 
                    // NUMBERS FROM 1 - 9 TO SEE WHETHER WE WILL BE ABLE TO DO OR NOT
                    for (char ch = '1'; ch<='9'; ch++){
                        if (isValid(board,i,j,ch)){
                            board[i][j] = ch;

                            if (solve(board) == true) return true;
                            
                            else{
                                board[i][j] = '.';
                            }
                        
                        }


                    }

                    // AFTER CHECKING EVERY ELEMENT OF THE BOARD I WAS NOT ABLE TO 
                    // GET A VALID NUMBER IN SUDOKU AS A RESULT OF WHICH I HAD TO 
                    // RETURN A FALSE BCOZ IT CAN NOT BE MY ANSWER
                    
                    return false;
                }
            }
        }

        return true;
    }
    bool isValid(vector<vector<char>>& board, int row, int col, char ch){
        for (int i=0; i<9; i++){
            // CHEECKING THE ENTIRE ROW
            if (board[row][i] == ch) return false;
            // CHEECKING THE ENTIRE COLUMN
            if (board[i][col] == ch) return false;
            // CHECKING FOR THE ENITRE 3X3 BOARD
            if (board[3*(row/3) + i/3][3*(col/3) + i%3] == ch) return false;   
        }

        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
        return ;
    }
};