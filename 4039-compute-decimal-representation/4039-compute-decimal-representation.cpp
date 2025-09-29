class Solution {
public:
    vector<int> decimalRepresentation(int n) {
        string s=to_string(n);
        int nn=s.size();
        vector<int>v;
        for(int i=0;i<nn;i++){
            if(s[i]>='1' and s[i]<='9')v.push_back((s[i]-'0')*pow(10,nn-1-i));
        }
        return v;
    }
};