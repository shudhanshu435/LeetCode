class Solution {
public:
    int binNeg(vector<int>& nums, int l, int r){
        int ans = 0;
        while(l<=r){
            int mid=(l+r)/2;
            if(nums[mid]>=0){
                r=mid-1;
            }else{
                ans = mid+1;
                l=mid+1;
            }
        }
        return ans;
    }
    int binPos(vector<int>& nums, int l, int r){
        int ans = 0, n=r+1;
        while(l<=r){
            int mid=(l+r)/2;
            if(nums[mid]<=0){
                l=mid+1;
            }
            else {
                ans=n-mid;
                r=mid-1;
            }
        }
        return ans;
    }
    int maximumCount(vector<int>& nums) {
        int n=nums.size();
        if(nums[0]>0 or nums[n-1]<0)return n;
        int neg=binNeg(nums,0,n-1);
        int pos=binPos(nums,0,n-1);
        // cout<<pos<<" "<<neg<<endl;
        return max(neg,pos);
    }
};