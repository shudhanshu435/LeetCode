class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        int i;
        int ans=INT_MAX;
        for(i=n-2;i>=0;i--){
            int ind;
            if(nums[i]<nums[i+1]){
                int k=i+1;
                while(k<n){
                    if(nums[k]>nums[i]){
                        if(ans>nums[k]){
                            ind=k;
                            ans=nums[k];
                        }
                    }
                    k++;
                }
                swap(nums[i],nums[ind]);
                sort(nums.begin()+(i+1),nums.end());
                break;
            }
        }
        if(i==-1)reverse(nums.begin(),nums.end());
    }
};