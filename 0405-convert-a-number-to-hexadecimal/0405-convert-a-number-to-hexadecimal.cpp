class Solution {
public:
    string toHex(int num) {
        unsigned int n=num;
        string ans="",c="abcdef";
        if(num==0)return "0";
        while(n){
            int d=n%16;
            if(d<=9)ans+=(d+'0');
            else ans+=c[d-10];
            n/=16;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};