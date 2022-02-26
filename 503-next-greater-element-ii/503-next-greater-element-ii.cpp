class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int>vec,res;
        vec=nums;
        int cnt=0;
        for(int i=0;i<nums.size();i++){
            cnt=0;
            for(int j=i;j<nums.size();j++){
                if(nums[j]>nums[i]){
                    res.push_back(vec[j]);
                    cnt++;
                    break;
                }
                if(j==(nums.size()-1) && cnt==0){
                    for(int j=0;j<i;j++){
                        if(nums[j]>nums[i]){
                        res.push_back(vec[j]);
                        cnt++;
                        break;
                        }
                     }
                }
            }
            if(cnt==0)res.push_back(-1);
        }
        return res;
    }
};
