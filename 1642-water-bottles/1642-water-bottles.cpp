class Solution {
public:
    int numWaterBottles(int full, int nx) {
        int ans=full;
        while(1){
            int div=full/nx;
            int rem=full%nx;
            ans+=div;
            full=div+rem;
            if(full<nx)break;
        }
        return ans;
    }
};