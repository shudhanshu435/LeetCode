class Solution {
public:
    long long maxProfit(vector<int>& pp, vector<int>& ss, int k) {
         int n=pp.size();
        vector<long long>a(n);
        long long base=0;
        for(int i=0;i<n;i++){
            a[i]=1LL*pp[i]*ss[i];
            base+=a[i];
        }

        vector<long long>preA(n+1),preP(n+1);
        for(int i=0;i<n;i++){
            preA[i+1]=preA[i]+a[i];
            preP[i+1]=preP[i]+pp[i];
        }

        long long best=0;
        int h=k/2;
        for(int l=0;l+k<=n;l++){
            long long oldv=preA[l+k]-preA[l];
            long long newv=preP[l+k]-preP[l+h];
            best=max(best,newv-oldv);
        }

        return base+best;
    }
};
