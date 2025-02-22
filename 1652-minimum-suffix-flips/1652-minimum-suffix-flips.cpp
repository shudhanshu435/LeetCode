class Solution {
public:
    int minFlips(string target) {
        // string ans="";
        int cnt=1;
        for(int i=0;i<target.size()-1;i++){
            if(target[i]!=target[i+1])cnt++;
        }
        if(target[0]=='0')return cnt-1;
        return cnt;
    }
};

/*

101010011000 

000000000000

*/