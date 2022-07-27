class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int>vec;
        unordered_map<int,int>mp;
        int ans=0;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        for(auto i: mp){
            if(i.second ==1) vec.push_back(i.first);
        }
        return vec;
    }
};