class Solution {
public:
    bool squareIsWhite(string coordinates) {
        int t=coordinates[0];
        int m=coordinates[1];
        if(t&1){
            if(m&1)return 0;
            else return 1;
        }
        else{
            if(m&1)return 1;
            else return 0;
        }
        return 0;
    }
};