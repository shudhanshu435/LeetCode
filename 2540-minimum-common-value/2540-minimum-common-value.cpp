class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int i=0,j=0;
        int n=nums1.size(),m=nums2.size();
        int num=INT_MAX;
        while(i<n and j<m){
            if(nums1[i]==nums2[j]){
                num=min(num,nums1[i]);
                i++,j++;
            }
            else if(nums1[i]<nums2[j])i++;
            else j++;
        }
        return (num==INT_MAX)?-1:num;
    }
};