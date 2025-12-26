class Solution {
public:
    string longestPrefix(string s) {
        int n=s.length();
        vector<int>v(n,0);
        int len=0,i=1;
        while(i<n){
            if(s[len]==s[i]){
                len++;
                v[i]=len;
                i++;
            }
            else{
                if(len==0)i++;
                else len=v[len-1];
            }
        }
        // for(auto i:v)cout<<i<<  " ";
        if(v[n-1]==0)return "";
        return s.substr(n-v[n-1],v[n-1]);
    }
};