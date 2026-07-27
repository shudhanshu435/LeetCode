class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int l=0,s=0;
        for(auto &i:nums){
            if(i>=s){
                l=s;
                s=i;
            }
            else l=max(l,i);
        }
        return (l-1)*(s-1);
    }
};