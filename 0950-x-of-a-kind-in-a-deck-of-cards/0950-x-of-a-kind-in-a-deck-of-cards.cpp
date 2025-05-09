class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        unordered_map<int,int>mp;
        for(auto i:deck)mp[i]++;
        int x=0;
        for(auto i:mp){
            x=__gcd(x,i.second);
        }
        if(x==1)return 0;
        return 1;
    }
};