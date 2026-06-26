class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int tt) {
        unordered_map<int,int>mp;
        mp[0]=1;
        int n=nums.size();
        long long curr=0;
        long long val=0, res=0;
        for(int i=0;i<n;i++){
            if(nums[i]==tt){
                val+=mp[curr];
                curr++;
            }
            else{
                curr--;
                val-=mp[curr];
            }
            mp[curr]++;
            res+=val;
        }
        return res;
    }
};