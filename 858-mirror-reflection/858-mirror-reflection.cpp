class Solution {
public:
    int mirrorReflection(int p, int q) {
        int num=(p*q)/__gcd(p,q);
        int a = num/p;
        int b = num/q;
        if(a%2==0)return 0;
        else if(b%2==0)return 2;
        else return 1;

    }
};