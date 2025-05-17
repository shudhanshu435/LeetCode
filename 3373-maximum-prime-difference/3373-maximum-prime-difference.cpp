class Solution {
public:
    bool isPrime(int n){
        if(n<=1)return 0;
        if(n==2 or n==3)return 1;
        if(n%2==0 or n%3==0)return 0;
        for(int i=5;i*i<=n;i+=6){
            if(n%i==0 or n%(i+2)==0)return 0;
        }
        return 1;
    }
    int maximumPrimeDifference(vector<int>& nums) {
        int m=1;
        int first,sec;
        for(int i=0;i<nums.size();i++){
            if(isPrime(nums[i]) and m==1){
                first=i;
                sec=i;
                m=0;
            }
            else if(isPrime(nums[i]))sec=i;
        }
        return sec-first;
    }
};