class Solution {
public:
    string makeFancyString(string s) {
        string ans="";
        int n=s.length();
        if(n<=2)return s;
        int f=0,ss=1;
        ans+=s[0];ans+=s[1];
        for(int i=2;i<n;i++){
            if(ans[f]==ans[ss] and ans[ss]==s[i])continue;
            else {
                ans+=s[i];
                f=ans.size()-2;
                ss=ans.size()-1;
            }
        }
        return ans;
    }
};