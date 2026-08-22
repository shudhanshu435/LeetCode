class Solution {
public:
    bool checkDivisibility(int n) {
        int s=0,m=n,p=1;
        while(m){
            s+=m%10;
            p*=m%10;
            m/=10;
        }
        return (n%(p+s)==0);
    }
};