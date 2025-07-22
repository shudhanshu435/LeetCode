class Solution {
public:
    bool find_count(vector<int>&nums, int mid, int k){
        int cnt=0;
        for(int i=0;i<nums.size();i++){
            int num=nums[i]+mid;
            auto it=upper_bound(nums.begin(),nums.end(),num);
            int ind=it-nums.begin();
            cnt+=ind-i-1;
            if(cnt>=k)return 1;
        }
        return 0;
    }
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int max_d=nums[n-1]-nums[0];
        int ans=0;
        int min_d=0;
        while(min_d<=max_d){
            int mid=min_d+(max_d-min_d)/2;
            if(find_count(nums,mid,k)){
                ans=mid;
                max_d=mid-1;
            }
            else{
                min_d=mid+1;
            }
        }
        return ans;
    }
};

// 1 1 2 2 3 3