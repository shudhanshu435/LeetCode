class Solution {
public:
    bool isPowerOfFour(int n) {
        long long int mul=1,count=0;
        if(n==1)return true;
        for(long long int i=0;i<100000000;i++)
        {
            mul=mul*4;
            if(mul==n)count++;
            else if(mul>n)break;
        }
        if(count!=0)return true;
        else return false;
    }
};