class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            int ele=nums[i];
            if(ele>=1 and ele<=n){
                int ch=ele-1;
                if(nums[ch]!=ele){
                    swap(nums[ch],nums[i]);
                    i--;
                }
            }
        }
        for(int i=0;i<n;i++){
            if(nums[i]!=i+1)return i+1;
        }
        return n+1;
    }
};