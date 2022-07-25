class Solution {
public:
    
    int first(vector<int>vec , int tar){
        int l=0;
        int r=vec.size()-1;
        int mid=0;
        int ans=-1;
        while(l<=r){
            mid=l+(r-l)/2;
            if(vec[mid]==tar){
                ans=mid;
                r=mid-1;
            }
            else if(vec[mid]>tar)r=mid-1;
            else l=mid+1;
        }
        return ans;
    }
    
    int last(vector<int>vec , int tar){
        int l=0;
        int r=vec.size()-1;
        int mid=0;
        int ans=-1;
        while(l<=r){
            mid=l+(r-l)/2;
            if(vec[mid]==tar){
                ans=mid;
                l=mid+1;
            }
            else if(vec[mid]>tar)r=mid-1;
            else l=mid+1;
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        return {first(nums,target),last(nums,target)};
        
    }
};