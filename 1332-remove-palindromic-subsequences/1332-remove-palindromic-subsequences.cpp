class Solution {
public:
    int removePalindromeSub(string s) {
        int m=s.length()/2,cnt=0;
        for(int i=0;i<m;i++){
            if(s[i]!=s[s.length()-1-i]){cnt++;break;}
        }
        if(cnt!=0)return 2;
        else return 1;
    }
};
