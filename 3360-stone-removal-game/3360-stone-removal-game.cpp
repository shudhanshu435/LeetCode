class Solution {
public:
    bool canAliceWin(int n) {
        int k=10;
        if(n<10)return 0;
        while(n>=k){
            n-=k;
            k--;
        }
        if(k&1)return 1;
        return 0;
    }
};