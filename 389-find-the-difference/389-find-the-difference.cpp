class Solution {
public:
    char findTheDifference(string s, string t) {
        int sum1=0,sum2=0;
        for(int i=0;i<s.length();i++)sum1+=s[i];
        for(int i=0;i<t.length();i++)sum2+=t[i];
        int res=sum2-sum1;
        return abs(res);
    }
};