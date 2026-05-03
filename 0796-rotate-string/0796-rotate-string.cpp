class Solution {
public:
    bool rotateString(string s, string goal) {
        int n=s.length();
        s+=s;
        int i=0;
        while(i<n){
            if(s.substr(i,n)==goal)return 1;
            i++;
        }
        return 0;
    }
};