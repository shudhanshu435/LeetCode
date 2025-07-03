class Solution {
public:
    string con(string &a){
        string m="";
        for(auto i:a){
            if(i=='z')m+='a';
            else m+=(i+1);
        }
        return m;
    }
    char kthCharacter(int k) {
        string s="a";
        while(s.length()<k){
            string ss=con(s);
            s+=ss;
        }
        return s[k-1];
    }
};