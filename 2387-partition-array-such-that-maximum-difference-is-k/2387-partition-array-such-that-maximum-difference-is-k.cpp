class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int j=0,i=0;
        int c=0;
        int cnt=1,n=nums.size();
        if(nums.size()==1)return 1;

        for(i=j+1;i<n;i++){
            if(nums[i]-nums[j]<=k){
                continue;
            }
            else{
                cnt++;
                j=i;
            }
        }
        if(i==n)return cnt;

        return cnt-1;
    }
};