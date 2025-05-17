class Solution {
public:
    long long gcd(long long a, long long b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    long long lcm(long long a, long long b) {
        return (a / gcd(a, b)) * b;
    }

    bool pos(int mid, int d1, int d2, int u1, int u2){
        int div1=mid-(mid/d1);
        int div2=mid-(mid/d2);
        long long cnt=mid-mid/d1-mid/d2+mid/lcm(d1,d2);

        long long onlyForArr1 = div1 - cnt;
        long long onlyForArr2 = div2 - cnt;

        long long needFromCommonForArr1 = max(0LL, u1 - onlyForArr1);
        long long needFromCommonForArr2 = max(0LL, u2 - onlyForArr2);

        return (needFromCommonForArr1 + needFromCommonForArr2 <= cnt);
    }
    int minimizeSet(int d1, int d2, int u1, int u2) {
        long long l=1,r=1e18;
        long long ans=0;
        while(l<=r){
            long long mid=l+(r-l)/2;
            if(pos(mid,d1,d2,u1,u2)){
                ans=mid;
                r=mid-1;
            }
            else l=mid+1;
        }
        return ans;
    }
};

/*

1 3 5 7 9 11 13 15 17 19 21 23 25 27
1 2 3 4 5 6 8 9 10 11 12 13 15 16 17 18 19 20 

*/