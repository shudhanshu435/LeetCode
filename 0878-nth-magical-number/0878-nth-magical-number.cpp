class Solution {
public:
    bool check(long long mid, long long a, long long b, long long n){
        if(n<=((mid/a)+(mid/b)-((mid*__gcd(a,b))/(a*b))))return 1;
        return 0;
    }
    int nthMagicalNumber(int n, int a, int b) {
        long long maxi=1e18;
        long long ans=0;
        long l=0,r=1e14;
        while(l<=r){
            long long mid=l+(r-l)/2;
            if(check(mid,a,b,n)){
                ans=mid;
                r=mid-1;
            }
            else l=mid+1;
        }
        return ans%1000000007;;
    }
};