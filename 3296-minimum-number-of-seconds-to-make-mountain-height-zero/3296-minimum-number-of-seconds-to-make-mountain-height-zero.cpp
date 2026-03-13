class Solution {
public:
    bool pos(long long mid, int mh, vector<int>& work){
        long long s=0;
        for(auto i:work){
            long long m=mid/i;
            long long k = (-1 + sqrt(1 + 8.0*m)) / 2;
            s+=k;
            if(s>=mh)return 1;
        }
        // cout<<endl;
        return 0;
    }

    long long minNumberOfSeconds(int mh, vector<int>& work) {
        long long l=1,r=1e18;
        long long ans=0;
        while(l<=r){
            long long mid=l+(r-l)/2;
            if(pos(mid,mh,work)){
                ans=mid;
                r=mid-1;
            }
            else l=mid+1;
        }
        return ans;
    }
};