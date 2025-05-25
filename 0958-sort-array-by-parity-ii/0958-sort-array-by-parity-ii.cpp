class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int n=nums.size();
        int o=1,e=0;
        vector<int>v(n);
        for(int i=0;i<n;i++){
            if(nums[i]&1){
                v[o]=nums[i];
                o+=2;
            }
            else{
                v[e]=nums[i];
                e+=2;
            }
        }
        return v;
    }
};