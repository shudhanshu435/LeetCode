class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int c1=0,cnt1=0,c2=0,cnt2=0;
        int n=nums.size();
        for(auto x:nums){
            if(x==c1)cnt1++;
            else if(x==c2)cnt2++;
            else if(cnt1==0)c1=x,cnt1=1;
            else if(cnt2==0)c2=x,cnt2=1;
            else cnt1--,cnt2--;
        }
        cnt1=0,cnt2=0;
        for(auto i:nums){
            if(i==c1)cnt1++;
            else if(i==c2)cnt2++;
        }
        if(cnt1>(n/3) and cnt2>(n/3))return {c1,c2};
        else if(cnt1>(n/3))return {c1};
        else if(cnt2>(n/3))return {c2};
        return {};
    }
};