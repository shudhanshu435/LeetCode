class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int n=nums.size();
        int i=0,o=n-1,e=n-2;
        while(i<=o and i<=e){
            if((i%2)==(nums[i]%2))i++;
            else{
                if(i&1){
                    swap(nums[i],nums[e]);
                    e-=2;
                }
                else{
                    swap(nums[i],nums[o]);
                    o-=2;
                }
            }
        }
        return nums;
    }
};