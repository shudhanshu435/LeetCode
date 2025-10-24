class Solution {
public:
    bool func(long long n, long long &ans){
        vector<int>v(10,0);
        long long m=n;
        while(n){
            v[n%10]++;
            n/=10;
        }
        for(int i=0;i<10;i++){
            if(i==0 and v[i]!=0)return 0;
            if(v[i]!=0 and v[i]!=i)return 0;
        }
        ans=m;
        return 1;
    }
    int nextBeautifulNumber(int n) {
        long long m=(long long)n;
        m++;
        long long ans=0;
        while(1){
            if(bool(func(m,ans))){
                return ans;
            }
            m++;
        }
    }
};