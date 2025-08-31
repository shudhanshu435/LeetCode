class Solution {
public:
    bool isval(vector<vector<char>>& board, int row, int col, char d) {
    for (int i = 0; i < 9; i++) {
        if (board[row][i] == d) return false; // row check
        if (board[i][col] == d) return false; // col check
        int gridRow = 3 * (row / 3) + i / 3;
        int gridCol = 3 * (col / 3) + i % 3;
        if (board[gridRow][gridCol] == d) return false; // box check
    }
    return true;
}

    bool solve(vector<vector<char>>& board){
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.'){
                    for(char d='1';d<='9';d++){
                        if(isval(board,i,j,d)){
                            board[i][j]=d;
                            if(solve(board))return true;
                            board[i][j]='.';
                        }
                    }
                    return 0;
                }
            }
        }
        return 1;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};