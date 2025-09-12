class Solution {
public:
    bool doesAliceWin(string s) {
        int c=0;
        for(auto &i:s){
            if(i=='a' or i=='e' or i=='i' or i=='o' or i=='u')c++;
        }
        return c!=0;
    }
};