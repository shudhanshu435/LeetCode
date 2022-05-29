class Solution {
public:
    int findMin(vector<int>& nums) {
        if(nums.size()==1)return nums[0];
        
        int l=0,h=nums.size()-1,mid=0;
        int cnt=0;
        while(l<=h){
            mid=(l+h)/2;
            if(nums[l]<=nums[h]){
                cnt=nums[l];
                break;
            }
            else if(nums[l]<=nums[mid]){
                l=mid+1;
            }else{
                h=mid;
            }
        }
        return cnt;
        
        
        
    }
};