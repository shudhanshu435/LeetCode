using ll=long long;
class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        if(num1==0)return 0;
        int k=1;
        while(1){
            long long n=num1-(k*1ll*num2);
            if(n<=0)return -1;
            long long cnt=0,m=n;
            while(n){
                if(n&1)cnt++;
                n/=2;
            }
            if(cnt<=k and k<=m)return k;
            k++;
        }
        return -1;
    }
};