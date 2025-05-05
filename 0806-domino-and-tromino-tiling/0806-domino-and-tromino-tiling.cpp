class Solution {
public:
    int mod=1000000007;
    int numTilings(int n) {
        if(n==1)return 1;
        if(n==2)return 2;
        if(n==3)return 5;
        long long a=1,b=2,c=5,d;
        int i=4;
        while(i<=n){
            d=((c*1ll*2)%mod+a)%mod;
            a=b;
            b=c;
            c=d;
            i++;
        }
        return d;
    }
};