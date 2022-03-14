class Solution {
public:
    int smallestEqual(vector<int>& nums) {
        int ans=0,cnt=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==i%10){
                ans=i;
                cnt++;
                break;
            }
        }
        if(cnt!=0)return ans;
        else return -1;
    }
};
