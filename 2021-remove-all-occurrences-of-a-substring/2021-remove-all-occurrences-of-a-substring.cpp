class Solution {
public:
    string removeOccurrences(string s, string part) {
        stack<char>ss;
        int p=part.size();
        bool cnt=true;
        while(cnt){
            cnt=false;
            for(int i=0;i<s.length();i++){
                if(s[i]==part[0]){
                    if(s.substr(i,p)==part){
                        s.erase(i,p);
                        cnt=true;
                        break;
                    }
                }
            }
        }
        return s;
    }
};