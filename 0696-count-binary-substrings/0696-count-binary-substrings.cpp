class Solution {
public:
    int countBinarySubstrings(string s) {
        int one=0,zero=0,ans=0;
        vector<int>v;
        for(auto &i:s){
            if(i=='0'){
                if(one!=0)v.push_back(one);
                one=0;
                zero++;
            }
            else{
                if(zero!=0)v.push_back(zero);
                zero=0;
                one++;
            }
        }
        v.push_back(zero+one);
        for(int i=0;i<v.size()-1;i++){
            ans+=min(v[i],v[i+1]);
        }
        return ans;
    }
};