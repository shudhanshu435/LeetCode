class Solution {
public:
    bool isPalindrome(int x){

        if(x == 0) return 1;
        if(x < 0 || x%10 == 0)return 0;

        long long int m=x,sum=0;    ///346
        while(x!=0){
            int t=x%10;
            sum=sum*10+t;
            x/=10;
        }
        if(m==sum)return true;
        else return false;


    }
};