class Solution {
public:
    string getSmallestString(string s) {
        int n=s.length();
        for(int i=0;i<n-1;i++){
            if((s[i]%2!=0 and s[i+1]%2!=0) or (s[i]%2==0 and s[i+1]%2==0)){
                if(s[i]>s[i+1]){
                    swap(s[i],s[i+1]);
                    break;
                }
            }
        }
        return s;
    }
};