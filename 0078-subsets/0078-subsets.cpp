class Solution {
public:
    void backtrack(vector<int>&nums, int index, vector<int>&v, set<vector<int>>&vec){
        if(index==nums.size()){
            vec.insert(v);
            return;
        }
        v.push_back(nums[index]);
        backtrack(nums,index+1,v,vec);
        v.pop_back();
        backtrack(nums,index+1,v,vec);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        set<vector<int>>vec;
        vector<int>v;
        backtrack(nums,0,v,vec);
        
        vector<vector<int>>vv(vec.begin(),vec.end());
        return vv;
    }
};