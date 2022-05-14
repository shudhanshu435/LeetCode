class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int cnt=0;
        vector<int>vec;
        int t=nums.size();
        for(int i=0;i<nums.size();i++){
            if(nums[i]==val){
                cnt++;
            }
            else vec.push_back(nums[i]);
        }
        nums.empty();
        nums=vec;
        return t-cnt;
    }
};