class Solution {
public:
    void expand(string &s, int i, int j, int  n, int &ss, int& ans){
        while(i>=0 and j<n and s[i]==s[j]){
            i--;j++;
        }
        int p=j-i-1;
        if(p>ans){
            ans=p;
            ss=i+1;
        }
    }
    string longestPalindrome(string s) {
        int ans=0;
        int n=s.length();

        int ss=0,maxi=0;
        for(int i=0;i<n;i++){
            expand(s,i,i,n,ss,maxi);
            expand(s,i,i+1,n,ss,maxi);
        }
        return s.substr(ss,maxi);
    }
};