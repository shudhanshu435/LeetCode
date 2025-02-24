class Solution {
public:
    unordered_map<int,int>mp;
    int solve(string& s, int i, int n){
        if(i==n){
            return 1;
        }
        if(s[i]=='0')return 0;
        if(mp.find(i)!=mp.end())return mp[i];
        int ans = solve(s,i+1,n);
        if(i+1<n){
            int num=(s[i]-'0')*10+(s[i+1]-'0');
            if(num>=10 and num<=26)ans+=solve(s,i+2,n);
        }

        return mp[i]=ans;

    }
    int numDecodings(string s) {
        mp.clear();
        int n=s.length();
        int ans=0;
        return solve(s,0,n);
    }
};