class Solution {
public:
    bool pos(int d1, int d2, int r1, int r2,long long mid){
        long long rem=mid-mid/r1;
        long long yem=mid-mid/r2;
        if(rem<d1 or yem<d2)return 0;

        long long tot=mid-(mid/((r1*1ll*r2)/__gcd(r1,r2)));
        if(tot>=d1+d2)return 1;
        return 0;
    }
    long long minimumTime(vector<int>& d, vector<int>& r) {
        long long l=1,h=1e18;
        long long ans=0;
        while(l<=h){
            long long mid=l+(h-l)/2;
            if(pos(d[0],d[1],r[0],r[1],mid)){
                ans=mid;
                h=mid-1;
            }
            else l=mid+1;
        }
        return ans;
    }
};