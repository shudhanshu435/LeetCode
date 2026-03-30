class Solution {
public:
    bool checkStrings(string s1, string s2) {
        string a="",b="",c="",d="";
        for(int i=0;i<s1.length();i++){
            if(i&1)a+=s1[i];
            else b+=s1[i];
        }
        for(int i=0;i<s1.length();i++){
            if(i&1)c+=s2[i];
            else d+=s2[i];
        }
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        sort(c.begin(),c.end());
        sort(d.begin(),d.end());
        return (a==c and b==d);
    }
};