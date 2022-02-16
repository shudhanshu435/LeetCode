class Solution {
public:
    bool judgeCircle(string moves) {
        int r=0,l=0,u=0,d=0;
        for(int i=0;i<moves.length();i++){
            if(moves[i]=='R')r++;
            else if(moves[i]=='L')l++;
            else if(moves[i]=='U')u++;
            else d++;
        }
        if((r==l)&&(u==d))return 1;
        else return 0;
    }
};