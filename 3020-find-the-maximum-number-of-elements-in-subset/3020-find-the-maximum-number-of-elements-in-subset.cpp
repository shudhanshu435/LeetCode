class Solution {   // 1 2 4 2 1
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<int,int>mp;
        int n=nums.size();
        for(auto &i:nums)mp[i]++;
        int ans=mp[1];
        if(ans==n)return (n&1)?n:n-1;
        ans=(mp[1]&1)?mp[1]:mp[1]-1;
        sort(nums.begin(),nums.end());
        for(int &x:nums){
            int cnt=0;
            int i=0;
            while(1){
                if(i>=63)break;
                long long k=(1ll<<i);
                double val=pow((double)x,(double)k);
                if(val>LLONG_MAX)break;
                long long num=(long long)val;
                if(mp[num]>=2){
                    cnt+=2;
                }
                else if(mp[num]==1){
                    cnt++;
                    ans=max(ans,cnt);
                    break;
                }
                else{
                    ans=max(ans,cnt-1);
                    break;
                }
                i++;
            }
        }
        return ans;
    }
};