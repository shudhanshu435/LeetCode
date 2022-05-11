class Solution {
public:
    int addDigits(int num) {
        long long int sum=0;
     while(num!=0)
     {
         long long int t=num%10;
         sum+=t;
         num/=10;
         if(num==0 && sum>=10)
         {
             num=sum;
             sum=0;
         }
     }
    return sum;
    }
};