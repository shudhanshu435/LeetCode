class Solution {
public:
    long long maxRunTime(int n, vector<int>& bb) {
        long long low=0;
        long long high=accumulate(bb.begin(),bb.end(),0ll)/n;

        auto canrun = [&](long  long T){
            long long sum=0;
            for(long long i:bb){
                sum+=min(i,T);
            }
            return sum>=n*T;
        };
        long long ans=0;
        while(low<=high){
            long long mid=(low+high)/2;
            if(canrun(mid)){
                ans=mid;
                low=mid+1;
            }
            else high=mid-1;
        }
        return ans;
    }
};