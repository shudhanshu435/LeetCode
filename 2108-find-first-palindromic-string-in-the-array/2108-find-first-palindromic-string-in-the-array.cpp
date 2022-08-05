class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        int ans=0;
        string t;
        for(int i=0;i<words.size();i++){
            string s=words[i];
            t=s;
            reverse(s.begin(),s.end());
            if(t==s){ans++;t=s;break;}
        }
        if(ans==0)return "";
        else return t;
    }
};