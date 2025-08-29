class Solution {
public:
    long long flowerGame(int n, int m) {
        int o1=0,e1=0; 
        int o2=0,e2=0;
        e1=n/2;
        if(n&1)o1=(n+1)/2;
        else o1=n/2;
        e2=m/2;
        if(m&1)o2=(m+1)/2;
        else o2=m/2;
        return (o1*1ll*e2)+(e1*1ll*o2);
    }
};