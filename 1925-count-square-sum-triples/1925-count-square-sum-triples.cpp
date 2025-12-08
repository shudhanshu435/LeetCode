class Solution {
public:
    int countTriples(int n) {
        int cnt=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                long long c=i*1ll*i+j*1ll*j;
                int sq=sqrt(c);
                if(sq*1ll*sq==c and sq<=n)cnt++;
            }
        }
        return cnt;
    }
};