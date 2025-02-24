class Solution {
public:
    int myAtoi(string s) {
        if(s=="-2147483647")return -2147483647;
        int i=0;
        int n=s.length();
        while(i<n and s[i]==' ')i++;
        char sign='+';
        if(i<n and s[i]=='-'){
            sign='-';
            i++;
        }
        else if(i<n and s[i]=='+')i++;
        long long ans=0;
        while(i<n and s[i]=='0')i++;
        while(i<n and s[i]>='0' and s[i]<='9'){
            ans=(ans*10+(s[i]-'0'));
            if(ans>INT_MAX)ans=INT_MAX;
            // if(ans<INT_MIN)ans=INT_MIN;
            i++;
        }
        if(ans!=0){
            if(sign=='-'){
                if(ans>=INT_MAX)return -1*(ans+1);
                return -1*(ans);
            }
            return ans;
        }
        return 0;
    }
};