class Solution {
public:
    int arraySign(vector<int>& nums) {
        int zer=0,neg=0,pos=0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                zer++;
                break;
            }
            else if(nums[i]<0)neg++;
            else pos++;
        }
        if(zer!=0)return 0;
        else if(neg%2!=0)return -1;
        else return 1;
    }
};