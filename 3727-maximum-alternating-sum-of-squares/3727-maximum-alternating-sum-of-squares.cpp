class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        vector<long long>v;
        for(auto i:nums)v.push_back(i*1ll*i);
        sort(v.begin(),v.end());
        long long ans=0;
        int i=0,j=v.size()-1,k=1;
        while(i<=j){
            if(k&1)ans+=v[j--];
            else ans-=v[i++];
            k++;
        }
        return ans;
    }
};