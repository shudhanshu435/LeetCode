class Solution {
public:
    int binNeg(vector<int>& nums, int l, int r){
        while(l<=r){
            int mid=(l+r)/2;
            if(nums[mid]<0){
                if(nums[mid+1]>=0)return mid+1;
                else l=mid+1;
            }
            else r=mid-1;
        }
        return 0;
    }
    int binPos(vector<int>& nums, int l, int r){
        while(l<=r){
            int mid=(l+r)/2;
            if(nums[mid]>0){
                if(nums[mid-1]<=0)return mid;
                else r=mid-1;
            }
            else l=mid+1;
        }
        return nums.size();
    }
    int maximumCount(vector<int>& nums) {
        int n=nums.size();
        if(nums[0]>0 or nums[n-1]<0)return n;
        int neg=binNeg(nums,0,n-1);
        int pos=binPos(nums,0,n-1);
        cout<<neg<<" "<<pos<<"\n";
        return max(neg,n-pos);
    }
};