class Solution {
public:

    string makeLargestSpecial(string s) {
        vector<string>v;
        int ss=0;
        int sum=0;
        for(int i=0;i<s.length();i++){
            sum+=s[i]=='1'?1:-1;
            if(sum==0){
                string inner=s.substr(ss+1,i-ss-1);
                v.push_back("1"+makeLargestSpecial(inner)+"0");
                ss=i+1;
            }
        }
        sort(begin(v),end(v),greater<string>());
        string res;
        for(string &s:v){
            res+=s;
        }
        return res;
    }
};