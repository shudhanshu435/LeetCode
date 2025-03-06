class Solution {
public:
    int bin(long long l, long long r){
        long long num=r;
        long long mid;
        while(l<=r){
            mid=(l+r)/2;
            if(mid*mid==num)return mid;
            else if(mid*mid>num)r=mid-1;
            else l=mid+1;
        }
        return r;
    }
    int mySqrt(int x) {
        return bin(0,1ll*x);
    }
};