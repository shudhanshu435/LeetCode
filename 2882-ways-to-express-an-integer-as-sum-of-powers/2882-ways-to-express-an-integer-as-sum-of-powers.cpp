class Solution {
public:
    void pop(int n, int x, vector<long long>&v){
        long long i=1;
        while((long long)pow(i,x)<=n){
            v.push_back((long long)pow(i,x));
            i++;
        }
    }
    int mod=1000000007;
    vector<vector<int>> memo;
    int countS(int idx, int sum, vector<long long>&nums){
        if(sum==0)return 1;
        if(idx>=nums.size())return 0;
        if(memo[idx][sum]!=-1)return memo[idx][sum];

        int not_take=countS(idx+1,sum,nums);

        int take=0;
        if(nums[idx]<=sum){
            take=countS(idx+1,sum-nums[idx],nums);
        }
        return memo[idx][sum]=(not_take + take)%mod;
    }

    int numberOfWays(int n, int x) {
        vector<long long>v;
        pop(n,x,v);
        // for(auto i:v)cout<<i<<" ";
        memo.assign(v.size()+1,vector<int>(n+1,-1));
        return countS(0,n,v);
        return 0;
    }
};