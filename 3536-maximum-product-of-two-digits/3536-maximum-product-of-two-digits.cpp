class Solution {
public:
    int maxProduct(int n) {
        string s=to_string(n);
        sort(s.begin(),s.end());
        int len=s.size();
        return (s[len-1]-'0') * (s[len-2]-'0');
    }
};