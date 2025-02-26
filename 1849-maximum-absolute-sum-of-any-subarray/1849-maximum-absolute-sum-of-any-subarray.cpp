class Solution {
public:
    int maxSum(vector<int> &arr) {
        int maxi=0,curr=0,neg=0,maxi2=INT_MIN;
        for(auto c:arr){
            curr+=c;
            if(c<0)neg++;
            maxi2=max(maxi2,c);
            maxi=max(maxi,curr);
            if(curr<0)curr=0;
        }
        if(neg==arr.size())return maxi2;
        return maxi;
    }
    int maxAbsoluteSum(vector<int>& nums) {
        int maxi=0;
        maxi=max(maxi,maxSum(nums));
        for(int i=0;i<nums.size();i++){
            nums[i]=nums[i]*(-1);
        }
        maxi=max(maxi,maxSum(nums));
        return maxi;
    }
};