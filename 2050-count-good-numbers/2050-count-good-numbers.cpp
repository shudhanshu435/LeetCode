class Solution {
public:
    int mod = 1e9 + 7;

    long long modPow(long long b, long long exp, long long ans){
        //recursive
        if(exp==0)return ans;
        if(exp&1)return modPow(b,exp-1,(ans*b)%mod);
        return modPow((b*b)%mod,exp/2,ans);

        ////iterative
        // long long ans=1;
        // while(exp>0){
        //     if(exp&1){
        //         ans=(ans*b)%mod;
        //         exp--;
        //     }
        //     else{
        //         b=(b*b)%mod;
        //         exp/=2;
        //     }
        // }
        // return ans;
    }

    int countGoodNumbers(long long n) {
        long long no_4=n/2;
        long long no_5=(n+1)/2;
        long long ans=1;

        return (modPow(5, no_5, ans) * modPow(4, no_4, ans)) % mod;
    }
};
