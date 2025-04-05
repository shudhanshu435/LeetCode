class Solution {
public:
    void gensubsets(vector<int>&nums, int index, vector<int>subset, vector<vector<int>>&sset){
        if(index==nums.size()){
            sset.push_back(subset);
            return;
        }

        subset.push_back(nums[index]);
        gensubsets(nums,index+1,subset,sset);
        subset.pop_back();
        gensubsets(nums,index+1,subset,sset);
    }
    int subsetXORSum(vector<int>& nums) {
        vector<vector<int>>sset;
        gensubsets(nums,0,{},sset);
        int sum=0;
        for(auto i:sset){
            int x=0;
            for(auto j:i){
                x^=j;
            }
            sum+=x;
        }
        return sum;
    }
};