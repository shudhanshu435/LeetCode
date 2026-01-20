class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2==0)ans.push_back(-1);
            else {
                int j=1;
                while(j+1<=nums[i]){
                    if((j | (j+1))==nums[i]){
                        ans.push_back(j);
                        break;
                    }
                    j++;
                }
            }
        }
        return ans;
    }
};