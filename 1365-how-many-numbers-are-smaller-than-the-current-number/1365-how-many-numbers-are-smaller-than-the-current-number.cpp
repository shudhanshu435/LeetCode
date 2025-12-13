class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int>v=nums;
        vector<int>ans;
        sort(v.begin(),v.end());
        for(int i:nums){
            auto it=lower_bound(v.begin(),v.end(),i)-v.begin();
            ans.push_back(it);
        }
        return ans;
    }
};