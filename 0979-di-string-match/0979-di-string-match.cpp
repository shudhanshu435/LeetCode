class Solution {
public:
    vector<int> diStringMatch(string s) {
        int st=0,en=s.length();
        vector<int>vec;
        for(auto i:s){
            if(i=='I')vec.push_back(st++);
            else vec.push_back(en--);
        }
        vec.push_back(st);
        return vec;
    }
};