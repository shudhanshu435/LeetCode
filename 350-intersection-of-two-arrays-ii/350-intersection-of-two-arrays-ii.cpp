class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        
        int size1=nums1.size();
        int size2=nums2.size();
        vector<int>vec;
        for(int i=0;i<size1;i++)
        {
            
             if(find(nums2.begin(), nums2.end(), nums1[i])!=nums2.end()){
                 auto index = find(nums2.begin(), nums2.end(), nums1[i]);
	                vec.push_back(nums1[i]);
                    nums2.erase(index);
                }
        }
        return vec;
    }
};
