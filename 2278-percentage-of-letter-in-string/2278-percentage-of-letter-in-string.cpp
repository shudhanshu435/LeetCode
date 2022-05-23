class Solution {
public:
    int percentageLetter(string s, char letter) {
        int cnt=0,len;
        len=s.length();
        for(int i=0;i<s.length();i++){
            if(s[i]==letter)cnt++;
        }
        cout<<cnt<<endl;
        cout<<len<<endl;
        int m=(cnt*100)/len;
        return m;
    }
};