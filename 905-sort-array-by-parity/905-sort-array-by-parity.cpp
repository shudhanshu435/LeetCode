class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums){
        vector<int>vec,od,ev;
        for(int i=0;i<nums.size();i++){
            if(nums[i]&1)od.push_back(nums[i]);
            else ev.push_back(nums[i]);
        }
        for(int i=0;i<nums.size();i++){
            if(i<ev.size())vec.push_back(ev[i]);
            else vec.push_back(od[i-ev.size()]);
        }
        return vec;
    }
};