class Solution {
public:
    string lexSmallest(string s) {
        int n=s.length();
        string ans="{";
        for(int i=1;i<=n;i++){
            string ss="";
            for(int j=i;j>0;j--){
                ss+=s[j-1];
            }
            ss.append(s.substr(i));
            ans=min(ans,ss);
            // cout<<ss<<endl;
            ss=s.substr(0,n-i);
            // cout<<ss<<endl;
            for(int j=n-1;j>=n-i;j--){
                ss+=s[j];
            }
            ans=min(ans,ss);
            // cout<<ss<<endl;
        }
        return ans;
    }
};