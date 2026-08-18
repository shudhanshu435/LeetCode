class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int n=nums.size();
        for(auto &i:nums)mp[i]++;
        if(k==n)return *max_element(nums.begin(),nums.end());
        if(k==1){
            int maxi=-1;
            for(auto &[a,b]:mp){
                if(b==1)maxi=max(maxi,a);
            }
            return maxi;
        }
        if(mp[nums[0]]==1 and mp[nums[n-1]]==1)return max(nums[0],nums[n-1]);
        if(mp[nums[0]]>1 and mp[nums[n-1]]>1)return -1;
        if(mp[nums[0]]>1)return nums[n-1];
        return nums[0];
    }
};