class Solution {
public:
    bool isSolved(vector<vector<char>>& board){
        int n = board.size();
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(board[i][j]=='.') return false;
            }
        }
        return true;
    }

    bool isSafe(vector<vector<char>>& board, int i, int j, char k){
        int n = board.size();
        for(int p=0; p<n; p++){
            if(board[p][j]==k)
            return false;
        }

        for(int p=0; p<n; p++){
            if(board[i][p]==k)
            return false;
        }

        int b_row = (i/3)*3;
        int b_col = (j/3)*3;

        for(int q=b_row; q<b_row+3; q++){
            for(int r=b_col; r<b_col+3; r++){
                if(board[q][r]==k)
                return false;
            }
        }
        return true;
    }

    bool solveBoard(vector<vector<char>>& board){
        // Base Case
        int n = board.size();
        if(isSolved(board))
        return true;

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(board[i][j]=='.'){
                    for(char k='1';k<'10';k++){
                        if(isSafe(board,i,j,k)){
                            board[i][j]=k;
                        

                        if(solveBoard(board))
                        return true;

                        board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return false;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = board.size();
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(board[i][j]!='.'){
                    char ch = board[i][j];

                    board[i][j]='.';

                    if(!isSafe(board,i,j,ch))
                    return false;
                }
            }
        }
        return true;
    }
};
