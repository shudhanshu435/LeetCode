class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n=nums.size(), best=0;
        for(int i=0; i<n; i++){
            long long p=1,l=1;
            int g=0;
            for(int j=i; j<n; j++){
                int x=nums[j];
                p*=x;
                if(p>25200)break;     
                g=gcd(g,x);
                l=l/gcd(l,(long long)x)*x;
                if(p==l*g)best=max(best, j-i+1);
            }
        }
        return best;
    }
};