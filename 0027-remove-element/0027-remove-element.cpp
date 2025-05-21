class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i=0,j=nums.size()-1;
        int cnt=0;
        while(i<=j){
            if(nums[j]==val){
                j--;
                nums.pop_back();
                continue;
            }
            cnt++;
            swap(nums[j],nums[i]);
            i++;
        }
        return cnt;
    }
};