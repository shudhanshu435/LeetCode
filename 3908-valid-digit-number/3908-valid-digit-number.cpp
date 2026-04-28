class Solution {
public:
    bool validDigit(int n, int x) {
        bool b=0;
        while(n>9){
            if(n%10==x)b=1;
            n/=10;
        }
        if(n==x)return 0;
        return b;
    }
};