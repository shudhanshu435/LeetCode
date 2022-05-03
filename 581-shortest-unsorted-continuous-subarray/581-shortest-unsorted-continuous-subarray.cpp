class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int>vec;
        vec=nums;
        sort(nums.begin(),nums.end());
        if(nums==vec)return 0;
        int len=nums.size();
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=vec[i]){
                break;
            }else{
                len--;
            }
        }
        for(int i=nums.size()-1;i>=0;i--){
            if(nums[i]!=vec[i]){
                break;
            }else{
                len--;
            }
        }
        return len;
    }
};