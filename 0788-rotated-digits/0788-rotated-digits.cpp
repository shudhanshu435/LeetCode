class Solution {
public:
    bool pos(int n){
        bool b=0;
        while(n){
            int t=n%10;
            if(t==0 or t==1 or t==8 or t==2 or t==5 or t==6 or t==9){
                if(t==2 or t==5 or t==6 or t==9)b=1;
            }
            else return 0;
            n/=10;
        }
        return b;
    }
    int rotatedDigits(int n) {
        int cnt=0;
        for(int i=2;i<=n;i++){
            if(pos(i))cnt++;
        }
        return cnt;
    }
};