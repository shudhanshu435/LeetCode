class Solution {
public:
    int numberOfSubstrings(string s) {
        unordered_map<char,int>mp;
        int len=s.size();
        int start=0,ans=0;
        for(int i=0;i<s.length();i++){
            mp[s[i]]++;
            while(mp.size()>=3){
                // cout<<len-i<<endl;
                ans+=(len-i);
                mp[s[start]]--;
                if(mp[s[start]]==0)mp.erase(s[start]);
                start++;
            }
        }
        return ans;
    }
};