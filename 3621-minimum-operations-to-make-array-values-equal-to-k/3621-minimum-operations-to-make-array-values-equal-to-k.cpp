class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        vector<bool>v(101,false);
        int mini=101;
        int cnt=0;
        for(auto i:nums){
            if(v[i]==false){
                v[i]=true;
                cnt++;
                mini=min(mini,i);
            }
        }
        if(k>mini)return -1;
        if(k==mini)return cnt-1;
        return cnt;
    }
};