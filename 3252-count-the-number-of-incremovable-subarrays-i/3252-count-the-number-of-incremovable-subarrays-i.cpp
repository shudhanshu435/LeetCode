class Solution {
public:
    bool isStrictlyInc(vector<int>& nums) {
        if(nums.empty())return 1;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]>=nums[i+1])return 0;
        }
        return 1;
    }

    int incremovableSubarrayCount(vector<int>& nums) {
        int n=nums.size(),ans=0;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                vector<int>rem;
                for(int k=0;k<i;k++)rem.push_back(nums[k]);
                for(int k=j+1;k<n;k++)rem.push_back(nums[k]);

                if(isStrictlyInc(rem))ans++;
            }
        }

        return ans;
    }
};
