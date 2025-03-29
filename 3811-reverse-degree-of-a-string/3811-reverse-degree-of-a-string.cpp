class Solution {
public:
    int reverseDegree(string s) {
        int sc=0;
        for(int i=1;i<=s.length();i++){
            sc+=(i*(26-(s[i-1]-'a')));
        }
        return sc;
    }
};