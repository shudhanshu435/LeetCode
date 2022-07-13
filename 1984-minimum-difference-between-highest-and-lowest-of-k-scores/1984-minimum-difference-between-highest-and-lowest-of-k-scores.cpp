class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        vector<int>vec;
        for(int i=0;i<=nums.size()-k;i++){
            vec.push_back(abs(nums[i]-nums[i+k-1]));
        }
        sort(vec.begin(),vec.end());
        return vec[0];
    }
};