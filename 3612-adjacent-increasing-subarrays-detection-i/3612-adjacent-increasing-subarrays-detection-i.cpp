class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        bool f=0;
        int cnt=1;
        if(k==1)return 1;
        int maxi=0;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]<nums[i+1]){
                cnt++;
                maxi=max(maxi,cnt);
            }
            else{
                if(f and cnt>=k)return 1;
                if(cnt>=k)f=1;
                else f=0;
                cnt=1;
            }
        }
        if(maxi>=k*2)return 1;
        if(f and cnt>=k)return 1;
        return 0;
    }
};