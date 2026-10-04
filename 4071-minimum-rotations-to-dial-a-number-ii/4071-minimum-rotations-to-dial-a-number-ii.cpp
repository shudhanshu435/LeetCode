class Solution {
public:
    int minRotations(int n, string s) {
        int a=0,ans=0;
        for(int i=0;i<n;i++){
            int b=s[i]-'0';
            ans+=min(abs(a-b),10-abs(a-b));
            a=b;
        }
        int t=ans;
        a=0;
        int l=s[n-1]-'0';
        for(int i=0;i<n;i++){
            int b=s[i]-'0';
            int sub=min(abs(a-b),10-abs(a-b));
            int add=min(abs(a-l),10-abs(a-l));
            ans=min(ans,t-sub+add);
            a=b;
        }
        return ans;
    }
};