class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        vector<pair<int,int>>vp;
        for(auto i:arr){
            vp.push_back({__builtin_popcount(i),i});
        }
        sort(vp.begin(),vp.end());
        vector<int>v;
        for(auto i:vp)v.push_back(i.second);
        return v;
    }
};