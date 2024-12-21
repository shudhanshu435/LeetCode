class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        vector<int>vec;
        int n=s.length();
        for(int i=1;i<n;i++){
            if(n%i==0)vec.push_back(i);
        }
        for(int i=0;i<vec.size();i++){
            int len=vec[i];
            string ss=s.substr(0,len);
            string ans="";
            int new_len=0;
            while(new_len<n){
                ans+=ss;
                new_len+=len;
            }
            if(ans==s)return 1;
        }
        return 0;
    }
};