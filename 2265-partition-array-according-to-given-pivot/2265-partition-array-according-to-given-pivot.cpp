class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int>v,t,m;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<pivot)v.push_back(nums[i]);
            else if(nums[i]==pivot)t.push_back(nums[i]);
            else m.push_back(nums[i]);
        }
        for(auto i:t)v.push_back(i);
        for(auto i:m)v.push_back(i);
        return v;
    }
};