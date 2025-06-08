class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<pair<string,int>>vp;
        for(int i=1;i<=n;i++){
            vp.push_back({to_string(i),i});
        }
        sort(vp.begin(),vp.end());
        vector<int>ans;
        for(auto i:vp)ans.push_back(i.second);
        return ans;
    }
};