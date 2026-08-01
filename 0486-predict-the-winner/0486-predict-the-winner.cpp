class Solution {
public:
    int arr[21][21];
    int rec(vector<int>nums, int i, int j){
        if(i>j)return 0;
        if(i==j)return nums[i];
        if(arr[i][j]!=-1)return arr[i][j];
        int left = nums[i]+min(rec(nums, i+2,j), rec(nums, i+1,j-1));
        int right = nums[j]+min(rec(nums, i,j-2), rec(nums, i+1,j-1));

        return arr[i][j]=max(left,right);
    }
    bool predictTheWinner(vector<int>& nums) {
        int n=nums.size();
        int sum=accumulate(nums.begin(),nums.end(),0);
        memset(arr,-1,sizeof(arr));
        int val= rec(nums,0,n-1);
        if(val>=sum-val)return 1;
        return 0;
    }
};