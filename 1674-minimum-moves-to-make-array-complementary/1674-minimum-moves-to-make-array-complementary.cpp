class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        vector<long long>vec((2*limit)+2,0);
        unordered_map<int,int>mp;
        int n=nums.size();
        for(int i=0;i<n/2;i++){
            mp[nums[i]+nums[n-1-i]]++;
            int mini=min(nums[i],nums[n-i-1])+1;
            int maxi=max(nums[i],nums[n-1-i])+limit;
            vec[mini]+=1;
            vec[maxi+1]-=1;
        }

        for(int i=1;i<vec.size();i++){
            vec[i]=vec[i]+vec[i-1];
        }

        long long ans=n;
        for(int i=2;i<=2*limit;i++){
            ans=min(ans,vec[i]-mp[i]+((n/2)-vec[i])*2);
        }

        return ans;
    }
};