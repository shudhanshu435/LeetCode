class Solution {
public:
    int myAtoi(string s) {
        int i=0;
        int n=s.length();
        while(i<n and s[i]==' ')i++;
        int sign=1;
        if(i<n and (s[i]=='-' or s[i]=='+')){
            if(s[i]=='-')sign=-1;
            i++;
        }
        long long ans=0;
        while(i<n and s[i]=='0')i++;
        while(i<n and s[i]>='0' and s[i]<='9'){
            ans=(ans*10+(s[i]-'0'));
            if(sign==-1){
                if(ans>2147483648)return -2147483648;
            }
            else{
                if(ans>2147483647)return 2147483647;
            }
            i++;
        }
        return sign*ans;
    }
};