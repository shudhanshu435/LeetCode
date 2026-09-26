class Solution {
public:
    int minQueenMoves(vector<int>& s, vector<int>& t) {
        if(s[0]==t[0] and s[1]==t[1])return 0;
        if((s[0]==t[0]) or (s[1]==t[1]) or s[0]+s[1]==t[0]+t[1] or s[0]-s[1]==t[0]-t[1])return 1;
        return 2;
    }
};