class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int>vec;
        int j=0;
        for(int i=nums[0];i<nums[nums.size()-1];i++){
            if(i!=nums[j]){
                vec.push_back(i);
            }
            else j++;
        }
        return vec;
    }
};