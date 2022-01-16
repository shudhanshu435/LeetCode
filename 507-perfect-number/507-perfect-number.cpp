class Solution {
public:
    bool checkPerfectNumber(int num) {
        long long int sum=0;
        for(int i=1;i<sqrt(num);i++){
            if(num%i==0){
                sum+=i;
                int t=num/i;
                if(t!=i)sum+=t;
            }
        }
        if(sum-num==num)return true;
        else return false;
    }
};