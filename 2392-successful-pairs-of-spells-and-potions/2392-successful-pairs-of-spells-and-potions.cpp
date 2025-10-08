class Solution {
public:
    vector<int> successfulPairs(vector<int>& s, vector<int>& p, long long suc) {
        int n=p.size();
        sort(p.begin(),p.end());
        vector<int>v;

        for(auto &i:s){
            long long nn=ceil(suc/(double)i);
            auto it=lower_bound(p.begin(),p.end(),nn);
            int ind=it-p.begin();
            // cout<<ind<<" "<<nn<<endl;
            v.push_back(n-ind);
        }
        return v;
    }
};