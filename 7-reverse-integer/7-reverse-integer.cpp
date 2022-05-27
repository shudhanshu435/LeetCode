class Solution {
public:
    int reverse(int x) {
        long long int sum=0;
        while(x){
            int m=x%10;
            sum=sum*10+m;
            if(sum>pow(2,31)-1 || sum<-(pow(2,31)))return 0;
            x/=10;
        }
        if(x<0)return -(sum);
        else return sum;
    }
};