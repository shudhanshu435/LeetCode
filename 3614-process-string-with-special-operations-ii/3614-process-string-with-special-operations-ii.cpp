class Solution {
public:
    char processStr(string s, long long k) {
        long long len=0;
        int n=s.length();
        int i=0;
        for(;i<n;i++){
            if(isalpha(s[i])){
                len++;
            }
            else if(s[i]=='*')len=max(0ll,len-1);
            else if(s[i]=='#')len=len*2;
        }
        // cout<<len<<endl;
        if(k>=len)return '.';
        for(int i=n-1;i>=0;i--){
            char c=s[i];
            if(isalpha(c)){
                if(k==len-1)return c;
                len--;
            }
            else if(c=='#'){
                long long old=len/2;
                k=k%old;
                len=old;
            }
            else if(c=='%'){
                k=len-k-1;
            }
            else if(c=='*'){
                len++;
            }
        }
        return '.';
    }
};


// abc#%%**ccd