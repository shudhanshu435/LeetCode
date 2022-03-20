class Solution {
public:
    bool divideArray(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int cnt=0;
        for(int i=0;i<nums.size();i+=2){
            if(nums[i]!=nums[i+1]){
                cnt++;
                break;
            }
        }
        if(cnt==0)return 1;
        else return 0;
    }
};