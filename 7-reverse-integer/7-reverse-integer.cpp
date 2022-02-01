class Solution {
public:
    int reverse(int x) {
        long long int abs(x);
        long long int sum=0;
        while(x){
            sum=sum*10+(x%10);
            x/=10;
            if(sum > (pow(2,31)-1) || sum < -(pow(2,31)-1))return 0;
        }
        if(x<0)return (0-sum);
        else
        return sum;
    }
};