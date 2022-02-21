class Solution {
public:
    bool isPalindrome(string s) {
        
        string str="";
        for(int i=0;i<s.length();i++){
            if((s[i]>='A' && s[i]<='Z')||(s[i]>='a' && s[i]<='z')||(s[i]>='0' && s[i]<='9')){
                str+=tolower(s[i]);
            }
        }
        string res=str;
        reverse(str.begin(),str.end());
        if(res==str)return true;
        else return false;
    }
};