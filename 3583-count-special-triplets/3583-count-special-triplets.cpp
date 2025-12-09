class Solution {
public:
    int mod=1000000007;
    long long inv6=166666668;
    int specialTriplets(vector<int>& nums) {
        unordered_map<int,vector<int>>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]].push_back(i);
        }
        long long ans=0;
        long long z=mp[0].size();
        if(z>=3){
            long long temp=((z%mod)*((z-1)%mod)%mod * ((z-2)%mod))%mod;
            ans=(ans+temp*inv6%mod)%mod;
        }
        
        // 8 - [ 1,2,6,7]
        // 4 - [3,4,5]

        for(auto &[a,b]:mp){
            int n=b.size();
            if(a!=0 and a%2==0){
                if(!mp.count(a/2))continue;
                auto &vec=mp[a/2];
                for(int i=0;i<n-1;i++){
                    auto it=upper_bound(vec.begin(),vec.end(),b[i]);
                    auto itt=upper_bound(vec.begin(),vec.end(),b[i+1]);
                    int ind1=it-vec.begin();
                    int ind2=itt-vec.begin();
                    if(ind1<ind2){
                        int cnt=ind2-ind1;
                        long long add=((((long long)(i+1)*cnt)%mod)*(n-(i+1)))% mod;
                    ans = (ans + add) % mod;
                    }
                }
            }
        }
        return ans;
    }
};