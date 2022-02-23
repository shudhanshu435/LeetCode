class Solution {
public:
    string reverseOnlyLetters(string s) {
        vector<char>vec;
        for(int i=0;i<s.length();i++){
            if((s[i]>='A'&&s[i]<='Z')||(s[i]>='a'&&s[i]<='z'))
            vec.push_back(s[i]);
        }
        reverse(vec.begin(),vec.end());
        int k=0;
        for(int i=0;i<s.length();i++){
            if((s[i]>='A'&&s[i]<='Z')||(s[i]>='a'&&s[i]<='z'))
            {
                s[i]=vec[k];
                k++;
            }
        }
        return s;
    }
};