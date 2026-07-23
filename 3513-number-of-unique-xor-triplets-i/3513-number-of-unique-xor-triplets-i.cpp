class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n=nums.size();
        int tt=(n==0)?1:(int)log2(n) + 1;
        if(n==1 or n==2)return n;
        if(n==3)return n+1;
        return 1<<tt;
    }
};