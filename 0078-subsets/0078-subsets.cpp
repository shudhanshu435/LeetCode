class Solution {
public:
    void solve(vector<vector<int>>&vec, vector<int>v, vector<int>& nums, int ind){
        if(ind==nums.size()){
            vec.push_back(v);
            return;
        }
        solve(vec,v,nums,ind+1);
        v.push_back(nums[ind]);
        solve(vec,v,nums,ind+1);
        v.pop_back();

        return;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>vec;
        vector<int>v;
        solve(vec,v,nums,0);
        return vec;
    }
};