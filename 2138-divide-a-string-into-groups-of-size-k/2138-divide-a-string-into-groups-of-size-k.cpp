class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        int len = s.length();
        vector<string>vec;
        if(len%k==0){
            for(int i=0;i<len;i++){
                string ss="";
                ss=s.substr(i,k);
                vec.push_back(ss);
                i=i+k-1;
            }
        }  
        else {
            int m=s.length()%k;
            for(int i=0;i<k-m;i++){
                s+=fill;
            }
            for(int i=0;i<s.length();i++){
                string ss="";
                ss=s.substr(i,k);
                vec.push_back(ss);
                i=i+k-1;
            }
        }
        return vec;
    }
};


