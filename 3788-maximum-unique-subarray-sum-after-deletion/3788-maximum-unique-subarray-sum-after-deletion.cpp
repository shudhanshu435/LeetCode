class Solution {
public:
    int maxSum(vector<int>& nums) {
        set<int>s;
        for(int i=0;i<nums.size();i++){
            s.insert(nums[i]);
        }
        int ngmx=INT_MIN,sum=0,c=0;
        for(auto &i:s){
            if(i<0){
                ngmx=max(ngmx,i);
            }
            else {
                sum+=i;
                c++;
            }
        }
        if(c!=0)return sum;
        return ngmx;
    }
};