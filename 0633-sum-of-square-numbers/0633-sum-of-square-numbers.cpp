class Solution {
public:
    bool judgeSquareSum(int c) {
        long long j=sqrt(c);
        long long i=0;
        while(i<=j){
            if(i*i+j*j==c)return 1;
            if(i*i+j*j<c)i++;
            else j--;
        }
        return 0;
    }
};


