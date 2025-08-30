class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++){
            vector<int>vec(10,0),tec(10,0);
            for(int j=0;j<9;j++){
                if(board[i][j]!='.'){
                    vec[board[i][j]-'0']++;
                    if(vec[board[i][j]-'0']==2)return 0;
                }
                if(board[j][i]!='.'){
                    tec[board[j][i]-'0']++;
                    if(tec[board[j][i]-'0']==2)return 0;
                }
            }
        }
        vector<int>vec(10,0),tec(10,0),cec(10,0);
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(j<3){
                    if(board[i][j]!='.'){
                        vec[board[i][j]-'0']++;
                        if(vec[board[i][j]-'0']==2)return 0;
                    }
                }
                else if(j<6){
                    if(board[i][j]!='.'){
                        tec[board[i][j]-'0']++;
                        if(tec[board[i][j]-'0']==2)return 0;
                    }
                }
                else {
                    if(board[i][j]!='.'){
                        cec[board[i][j]-'0']++;
                        if(cec[board[i][j]-'0']==2)return 0;
                    }
                }
            }
            if(i==2 or i==5){
                vec.clear(),tec.clear(),cec.clear();
                vec.resize(10,0),tec.resize(10,0),cec.resize(10,0);
            }
        }
        return 1;
    }
};