class Solution {
public:
    int minimumLength(string s) {
        int i=0,j=s.length()-1;
        while(i<j){
            char ch=s[i];
            if(s[i]==s[j]){
                while(s[i]==ch and i<=j){
                    i++;
                }
                while(s[j]==ch and i<=j){
                    j--;
                }
            }
            else break;
        }
        return j-i+1;
    }
};