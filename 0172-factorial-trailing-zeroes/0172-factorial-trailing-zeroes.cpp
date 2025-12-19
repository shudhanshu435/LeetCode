class Solution {
public:
    int trailingZeroes(int n) {
        int ans=0;
        long long cur=5;
        int i=1;
        while(cur<=n){
            cur=(int)pow(5,i);
            i++;
            ans+=(n/cur);
        }
        return ans;
    }
};