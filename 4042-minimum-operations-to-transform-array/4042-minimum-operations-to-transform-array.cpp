class Solution {
public:
    long long minOperations(vector<int>& nums1, vector<int>& nums2) {
        long long ans=0;
        int n=nums1.size();
        bool b=0;
        int last=nums2[n];
        int mini=INT_MAX;
        for(int i=0;i<n;i++){
            ans+=abs(nums1[i]-nums2[i]);
            if((nums1[i]>=last and nums2[i]<=last) or (nums1[i]<=last and nums2[i]>=last)){
                b=1;
            }
            mini=min({mini,abs(nums1[i]-last),abs(nums2[i]-last)});
        }
        if(b)return ans+1;
        return ans+mini+1;
    }
};