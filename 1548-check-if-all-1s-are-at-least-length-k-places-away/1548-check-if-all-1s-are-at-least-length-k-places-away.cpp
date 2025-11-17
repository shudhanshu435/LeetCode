class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int n=nums.size();
        bool x=1;
        int a=INT_MIN;
        for(int i=0;i<n;i++){
            if(nums[i]==1){
                if(a!=INT_MIN){
                    if(i-a-1<k)return 0;
                    a=i;
                }
                else a=i;
            }
        }
        return 1;
    }
};