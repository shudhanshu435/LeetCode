class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        string ss="";
        while(n){
            ss+=n&1;
            n>>=1;
        }unsigned int t=0;
        for(int i=0;i<ss.length();i++){
            if(ss[i]==1)
                t+=1<<31-i;
        }
        return t;
    }
};