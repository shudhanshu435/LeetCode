class Solution {
public:
    string smallestNumber(string pattern) {
        int n=pattern.size();
        string s;
        s+='1';
        int size=0;
        for(int i=0;i<pattern.size();i++){
            int j=i;
            int num=i+2;
            s+=(num+'0');
            while(j>=0 and pattern[j]=='D'){
                swap(s[j],s[j+1]);
                j--;
            }
        }
        return s;
    }
};