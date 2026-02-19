class Solution {
public:
    int countBinarySubstrings(string s) {
        vector<int>v;
        int z=0,o=0,ans=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='0'){
                if(o!=0)v.push_back(o);
                z++;
                o=0;
            }
            else{
                if(z!=0)v.push_back(z);
                o++;
                z=0;
            }
        }
        v.push_back(z+o);
        for(int i=0;i<v.size()-1;i++){
            ans=ans+min(v[i],v[i+1]);
        }
        return ans;
    }
};