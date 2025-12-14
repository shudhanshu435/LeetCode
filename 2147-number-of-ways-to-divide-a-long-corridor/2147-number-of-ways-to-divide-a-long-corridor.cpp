class Solution {
public:
    const int MOD=1e9+7;
    int numberOfWays(string corridor) {

        int seats=0;
        for(char c:corridor)if(c=='S')seats++;
        if(seats==0 or seats%2!=0)return 0;

        long long ways=1;
        int s=0,p=0;
        for(char &ch:corridor){
            if(ch=='S'){
                s++;
                if(s-1>0 and (s-1)%2==0)ways=(ways*1ll*(p+1))%MOD;
                p=0;
            }
            else if(s>=2 and s%2==0){
                p++;
            }
        }
        return (int)ways;
    }
};