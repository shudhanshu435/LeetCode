class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int l=0,r=0;
        int n=moves.size();
        for(char i:moves){
            if(i=='L')l++;
            else if(i=='R')r++;
        }
        return abs(r-l)+n-(r+l);
    }
};