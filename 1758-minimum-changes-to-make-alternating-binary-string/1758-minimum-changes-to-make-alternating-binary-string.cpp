class Solution {
public:
    int minOperations(string s) {
        string ss="",tt="";
        int m=s.length();
        for(int i=0;i<m/2;i++){
            ss+='1';
            ss+='0';
            tt+='0';
            tt+='1';           
        }
        if(m&1){
            ss+='1';
            tt+='0';
        }
        int cn1=0,cn2=0;
        for(int i=0;i<m;i++){
            if(s[i]!=ss[i])cn1++;
            if(s[i]!=tt[i])cn2++;
        }
        return min(cn1,cn2);
    }
    
};