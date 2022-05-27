class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<=0)return 0;;
        if(n&(n-1))return 0;
        else return 1;
    }
};