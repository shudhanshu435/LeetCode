class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        // cout<<(10^5^2);
        int n=nums1.size();
        int m=nums2.size();
        if(n%2==0 and m%2==0)return 0;
        int xor1=0,xor2=0;
        for(auto i:nums1){
            xor1^=i;
        }
        for(auto i:nums2){
            xor2^=i;
        }
        if(n%2!=0 and m%2!=0)return xor1^xor2;
        if(n&1)return xor2;
        return xor1;


        return 0;
    }
};