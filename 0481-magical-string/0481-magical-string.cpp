class Solution {
public:
    int magicalString(int n) {
        string s="122";
        for(int i=2;i<s.size();i++){
            if(s[i]=='2'){
                if(s.back()=='2'){
                    s+='1';
                    s+='1';
                }
                else{
                    s+='2';
                    s+='2';
                }
            }
            else{
                if(s.back()=='1')s+='2';
                else s+='1';
            }
            if(s.size()>=n)break;
        }
        int one=0;
        for(int i=0;i<n;i++){
            if(s[i]=='1')one++;
        }
    return one;
    }
};