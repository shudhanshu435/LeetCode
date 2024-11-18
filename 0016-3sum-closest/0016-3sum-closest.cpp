class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int maxi=INT_MAX;
        int res=nums[0]+nums[1]+nums[2];
        for(int i=0;i<n-2;i++){
            int left=i+1;
            int right=n-1;
            while(left<right){
                int sum=nums[i]+nums[left]+nums[right];
                if(sum<target)left++;
                else if(sum>target)right--;
                else return target;

                int diff=abs(sum-target);
                if(diff<maxi){
                    res=sum;
                    maxi=diff;
                }
            }
        }
        return res;
    }
};