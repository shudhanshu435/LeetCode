class Solution {
public:
    string convertToTitle(int columnNumber) {
        int cc = columnNumber;
        string res = "";
        int rem;
        while(cc){
            rem = cc % 26;
            if(rem==0) rem = 26;
            char ch = 64 + rem;
            
            res = ch + res;
            cc = (cc - rem) / 26;
        }
        return res;
    }
};