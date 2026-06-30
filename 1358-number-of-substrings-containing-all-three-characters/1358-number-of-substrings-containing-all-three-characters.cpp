class Solution {
public:
    int numberOfSubstrings(string s) {
        int a=0,b=0,c=0;
        int n=s.length();
        int ans=0;
        int st=0;
        for(int k=0;k<n;k++){
            bool bb=0;
            if(s[k]=='a')a++;
            else if(s[k]=='b')b++;
            else c++;
            while(a>0 and b>0 and c>0){
                ans+=n-k;
                if(s[st]=='a')a--;
                else if(s[st]=='b')b--;
                else c--;
                st++;
            }
        }
        return ans;
    }
};