class Solution {
public:
    int longestSubstring(string s, int k) {
        int n=s.length();
        unordered_map<char,int>mp;
        for(auto i:s)mp[i]++;
        long long ans=0,curr=0,ind=0;
        for(int i=0;i<n;i++){
            if(mp[s[i]]>=k)curr++;
            else{
                ans=max(ans,curr);
                curr+=ind;
                while(ind<=curr){
                    mp[s[ind]]--;
                    if(mp[s[ind]]==0)mp.erase(s[ind]);
                    ind++;
                }
                curr=0;
            }
        }
        ans=max(ans,curr);
        return ans;
    }
};