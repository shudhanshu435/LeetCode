class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n=nums.size();
        vector<int>num(n);
        sort(nums.rbegin(),nums.rend());
        int k=0;
        for(int i=1;i<n;i+=2){
            num[i]=nums[k++];
        }
        for(int i=0;i<n;i+=2){
            num[i]=nums[k++];
        }
        nums.clear();
        nums=num;
    }
};