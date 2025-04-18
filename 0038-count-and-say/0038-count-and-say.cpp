class Solution {
public:
    string count(string& s){
        int cnt=1;
        string ans="";
        // cout<<s<<endl;
        for(int i=1;i<s.length();i++){
            if(s[i]==s[i-1])cnt++;
            else{
                ans+=to_string(cnt);
                ans+=s[i-1];
                cnt=1;
            }
        }
        ans+=to_string(cnt);
        ans+=s[s.length()-1];
        return ans;
    }
    string countAndSay(int n) {
        n--;
        string ans="1";
        while(n--){
            ans=count(ans);
            // cout<<ans<<endl;
        }
        return ans;
    }
};