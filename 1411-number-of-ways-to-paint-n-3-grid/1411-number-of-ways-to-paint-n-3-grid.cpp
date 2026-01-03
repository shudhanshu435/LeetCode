class Solution {
public:
    int numOfWays(int n) {
        int mod=1000000007;
        if(n==1)return 12;
        long long a=6,b=6;
        for(int i=2;i<=n;i++){
            long long na=(a*2+b*2)%mod;
            long long nb=(a*2+b*3)%mod;
            a=na;
            b=nb;
        }
        return (a+b)%mod;
    }
};