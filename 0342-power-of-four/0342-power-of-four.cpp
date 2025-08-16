class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n<=0)return 0;
        if(!(n&(n-1))){
            if(!((int)log2(n)&1))return 1;
        }
        return 0;
    }
};