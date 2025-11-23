class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        vector<int>one,two;
        int sum=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%3==1)one.push_back(nums[i]);
            else if(nums[i]%3==2)two.push_back(nums[i]);
            sum+=nums[i];
        }
        sort(one.begin(),one.end());
        sort(two.begin(),two.end());
        if(sum%3==0)return sum;
        if(sum%3==1){
            int cur=INT_MAX;
            if(one.size()>0)cur=min(cur,one[0]);
            if(two.size()>1)cur=min(cur,two[0]+two[1]);
            return sum-cur;
        }
        int cur=INT_MAX;
        if(one.size()>1)cur=min(cur,one[0]+one[1]);
        if(two.size()>0)cur=min(cur,two[0]);
        return sum-cur;
    }
};