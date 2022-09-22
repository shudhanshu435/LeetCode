class Solution {
public:
    string reverseWords(string s) {
        s.append(" ");
        string ans="",ss="";
        for(int i=0;i<s.length();i++){
            if(s[i]!=' '){
                ss+=s[i];
            }
            else{
                reverse(ss.begin(),ss.end());
                ans+=ss;
                ans+=' ';
                ss.clear();
            }
        }
        ans.pop_back();
        return ans;
    }
};