class Solution {
public:
    void gensubsets(vector<int>&nums, int index, vector<int>subset, vector<vector<int>>&sset){
        if(index==nums.size()){
            // sset.push_back(subset);
            if(find(sset.begin(),sset.end(),subset)==sset.end())sset.push_back(subset);
            return;
        }

        subset.push_back(nums[index]);
        gensubsets(nums,index+1,subset,sset);
        subset.pop_back();
        gensubsets(nums,index+1,subset,sset);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>sub;
        gensubsets(nums,0,{},sub);
        return sub;

    }
};