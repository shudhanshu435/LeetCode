class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int curr=nums[0]-k;
        int ans=1;
        int n=nums.size();
        for(int i=1;i<n;i++){
            if(curr+1<=nums[i]+k){
                curr=max(nums[i]-k,curr+1);
                ans++;
            }
        }
        return ans;
    }
};