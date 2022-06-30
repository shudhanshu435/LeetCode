class Solution {
public:
    string replaceDigits(string s) {
        for(int i=0;i<s.length();i++){
            int t=s[i];
            if(i&1)s[i]=s[i-1]+t-48;
        }
        return s;
    }
};