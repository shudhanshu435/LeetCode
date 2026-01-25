class Solution {
public:
    int countAsterisks(string s) {
        int cnt=0;
        int ind=0;
        int b=0;
        for(auto &i:s){
            if(i=='*'){
                if(b==0)cnt++;
            }
            if(i=='|'){
                b=b^1;
            }
        }
        return cnt;
    }
};