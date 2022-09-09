class Solution {
public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
        int siz=index.size();
        vector<int>tar;
        int i=0;
        while(i<siz){
            tar.insert(tar.begin() + index[i], nums[i]);
            i++;
        }
        return tar;
    }
};