class Solution {
public:
    bool isHappy(int n){
    
     long long int sum=0,count=0,m=1;
        while(m<100)
        {
            int t=n%10;
            sum=sum+(t*t);
            n/=10;
            if(n==0)
             {
                 n=sum;
                 sum=0;
                 if(n==1)return 1;
                 else continue;
             }
             m++;
        }
        
        return 0;

}
};