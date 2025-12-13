class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int cnt=0,maxi=0;
        for(int i:nums){
            if(i==1)cnt++;
            else cnt=0;
            maxi=max(maxi,cnt);
        }
        return maxi;
    }
};