class Solution {
public:
    int prefixConnected(vector<string>& words, int k) {
        unordered_map<string,int>mp;
        for(auto i:words){
            if(i.length()>=k)mp[i.substr(0,k)]++;
        }
        int cnt=0;
        for(auto [a,b]:mp){
            if(b>1)cnt++;
        }
        return cnt;
    }
};