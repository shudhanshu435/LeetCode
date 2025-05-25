class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        map<string,int>mp;
        int odd=0;
        int ans=0;
        for(auto &i:words)mp[i]++;
        // for(auto i:mp){
        //     cout<<i.first<<' '<<i.second<<endl;
        // }

        for(auto m:mp){
            if(m.second==0)continue;
            string s=m.first;
            if(s[0]==s[1]){
                ans+=(m.second/2)*4;
                if(m.second%2!=0)odd=2;
                mp[s]=0;
            }
            else{
                int f1=m.second;
                mp[s]=0;
                swap(s[0],s[1]);
                int f2=mp[s];
                ans+=min(f1,f2)*4;
                mp[s]=0;
            }
        }
        return ans+odd;
    }
};