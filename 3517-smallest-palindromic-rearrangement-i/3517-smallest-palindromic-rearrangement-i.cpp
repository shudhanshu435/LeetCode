class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int>v(26,0);
        for(auto i:s)v[i-'a']++;
        string ans="";
        int odd=-1;
        for(int i=0;i<26;i++){
            if(v[i]!=0){
                if(v[i]&1)odd=i;
                for(int k=0;k<v[i]/2;k++){
                    ans+=('a'+i);
                }
            }
        }
        if(odd!=-1){
            ans+=('a'+odd);
        }
        for(int i=25;i>=0;i--){
            if(v[i]!=0){
                for(int k=0;k<v[i]/2;k++){
                    ans+=('a'+i);
                }
            }
        }

        return ans;
    }
};