class Solution {
public:
    void func(vector<bool>&prime){
        prime[0]=0,prime[1]=0;
        for(int i=2;i*i<=100;i++){
            if(prime[i]){
                for(int j=i*i;j<=100;j+=i){
                    prime[j]=0;
                }
            }
        }
    }
    int maximumPrimeDifference(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        vector<bool>prime(101,1);
        func(prime);
        int m=1;
        int first,sec;
        for(int i=0;i<nums.size();i++){
            if(prime[nums[i]] and m==1){
                first=i;
                sec=i;
                m=0;
            }
            else if(prime[nums[i]])sec=i;
        }
        return sec-first;
    }
};