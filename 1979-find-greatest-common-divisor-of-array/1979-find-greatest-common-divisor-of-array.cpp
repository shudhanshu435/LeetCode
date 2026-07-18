class Solution {
public:
    int findGCD(vector<int>& nums) {
        int mini=INT_MAX;
        int maxi=INT_MIN;
        for(auto &i:nums){
            mini=min(mini,i);
            maxi=max(maxi,i);
        }
        return __gcd(mini,maxi);
    }
};