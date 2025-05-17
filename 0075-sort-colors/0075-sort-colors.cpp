class Solution {
public:
    void sortColors(vector<int>& nums) {
        int i=0,j=nums.size()-1,k=0;
        while(i<j+1){
            if(nums[i]==0){
                swap(nums[k++],nums[i]);
            }
            i++;
        }
        while(k<j){
            if(nums[k]==2){
                if(nums[j]!=2)swap(nums[k],nums[j]);
                else k--;
                j--;
            }
            k++;
        }
    }
};
/*

2 1 0 2 1 0
i=0,j=n-1

0 1 0 2 1 2
0 0 1 2 1 2
0 0 1 1 2 2

*/