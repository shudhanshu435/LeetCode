class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cur=0,cnt=0;
        for(auto i:nums){
            if(cnt==0){
                cur=i;
                cnt++;
            }
            else if(cur==i)cnt++;
            else if(cur!=i)cnt--;
        }
        return cur;
    }
};