class Solution {
public:
    int mod=1000000007;
    int numSub(string s) {
        s+='3';
        int one=0;
        long long ans=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='1'){
                one++;
            }
            else{
                ans=(ans+(one*1ll*(one+1)/2)%mod)%mod;
                one=0;
            }
        }
        return ans;
    }
};