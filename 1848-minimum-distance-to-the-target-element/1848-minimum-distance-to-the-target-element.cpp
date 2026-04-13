class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int i=start,j=start+1;
        int n=nums.size();
        int ans=INT_MAX;
        while(i>=0){
            if(nums[i]==target){
                ans=abs(i-start);
                break;
            }
            i--;
        }
        while(j<n){
            if(nums[j]==target){
                ans=min(ans,abs(j-start));
                break;
            }
            j++;
        }
        return ans;
    }
};