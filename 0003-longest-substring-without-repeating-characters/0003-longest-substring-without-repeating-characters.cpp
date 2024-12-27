class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>mp;
        int n=s.length();
        int maxi=INT_MIN;
        int k=0,i=0;
        for(i=0;i<n;i++){
            mp[s[i]]++;
            if(mp[s[i]]==2){
                maxi=max(maxi,i-k);
                char ch=s[i];
                while(mp[ch]!=1){
                    mp[s[k]]--;
                    k++;
                }
                // maxi=min(maxi,i-k);
            }
        }
        maxi=max(maxi,i-k);
        if(maxi==INT_MIN)return 0;
        return maxi;
    }
};