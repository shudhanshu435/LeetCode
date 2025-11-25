class Solution {
public:
    int smallestRepunitDivByK(int k) {
        unordered_map<int,int>mp;

        if(k==1)return 1;
        if(k%2==0 or k%10==5)return -1;
        int num=11;
        int cnt=2;
        while(1){
            int quo=num/k;
            if(quo==0)num=num*10+1;
            else{
                int rem=num%k;
                if(rem==0)return cnt;
                if(mp.count(rem)==1)return -1;
                mp[rem]++;
                num=rem*10+1;
            }
            cnt++;
        }
        return cnt;
    }
};