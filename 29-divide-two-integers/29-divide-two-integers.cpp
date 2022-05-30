class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == INT_MIN && divisor == -1)return INT_MAX;
        long long ans=0;
        
        long long dd = abs(dividend);
        long long dr = abs(divisor);
        int sign = (dividend>0) ^ (divisor>0) ? -1 : 1;
        
        
        while(dd>=dr){
            long long tmp=dr, cnt=1;
            while(dd-(tmp<<1)>=0){
                tmp<<=1;
                cnt<<=1;
            }
            ans+=cnt;
            dd-=tmp;
        }

        return sign * ans;
        
    }
};
