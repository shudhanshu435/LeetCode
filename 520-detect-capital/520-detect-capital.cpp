class Solution {
public:
    bool detectCapitalUse(string word) {
        int s=word.size(),cap=0,low=0;
        for(int i=0;i<word.size();i++){
            if(word[i]>='A' && word[i]<='Z')cap++;
            else if(word[i]>='a' && word[i]<='z')low++;
        }
        if(cap==s || low==s)return 1;
        else if((word[0]>='A' && word[0]<='Z') && (s-1==low))return 1;
        else return 0;
    }
};