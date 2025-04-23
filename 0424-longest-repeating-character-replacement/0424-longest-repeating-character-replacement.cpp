class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int>mp;
        int n=s.length();
        int st=0,ans=0,maxi=0;
        for(int i=0;i<n;i++){
            mp[s[i]]++;
            maxi=max(maxi,mp[s[i]]);
            while(i-st+1-maxi>k){
                mp[s[st]]--;
                st++;
                maxi=0;
                for(char ch='A';ch<='Z';ch++){
                    maxi=max(maxi,mp[ch]);
                }
            }
            if(i-st+1-maxi<=k){
                ans=max(ans,i-st+1);
            }
        }
        return max(ans,k);
    }
};

/*

BABB


*/