class Solution {
public:
    
    bool checkSq(vector<vector<char>>& board, int x, int y)
    {
        int hash[10] = {0};
        
        for(int i=x; i<x+3; i++)
            for(int j=y; j<y+3; j++)
            {
                if(board[i][j] != '.') ++hash[board[i][j]-'0'];
                
                if(board[i][j] != '.' and hash[board[i][j]-'0'] > 1)
                    return false;
            }
        
        return true;
    }
    
    bool isValidSudoku(vector<vector<char>>& board) 
    {        
        for(int i=0; i<9; i++)
        {
            int hash[10] = {0};
            for(int j=0; j<9; j++)
            {
                if(board[i][j] != '.') ++hash[board[i][j]-'0'];
                
                if(board[i][j] != '.' and hash[board[i][j]-'0'] > 1)
                    return false;
            }
        }
        
        for(int i=0; i<9; i++)
        {
            int hash[10] = {0};
            for(int j=0; j<9; j++)
            {
                if(board[j][i] != '.') ++hash[board[j][i]-'0'];
                
                if(board[j][i] != '.' and hash[board[j][i]-'0'] > 1)
                    return false;
            }
        }
        
        for(int i=0; i<9; i+=3)
            for(int j=0; j<9; j+=3)
                if(!checkSq(board, i, j))
                    return false;
        
        return true;
    }
};