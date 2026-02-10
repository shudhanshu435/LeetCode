class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        for(int i=0;i<n;i++){
            unordered_set<int>sev,sod;
            for(int j=i;j<n;j++){
                if(nums[j]%2==0)sev.insert(nums[j]);
                else sod.insert(nums[j]);

                if(sev.size()==sod.size()){
                    ans=max(ans,j-i+1);
                }
            }
        }
        return ans;
    }
};