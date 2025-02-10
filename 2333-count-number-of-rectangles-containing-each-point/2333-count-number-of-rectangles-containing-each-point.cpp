class Solution {
public:
    vector<int> countRectangles(vector<vector<int>>& rec, vector<vector<int>>& points) {
        map<int,vector<int>>mp;
        // sort(rec.begin(),rec.end());
        for(auto& i:rec){
            mp[i[1]].push_back(i[0]);
        }

        for (auto& it : mp) {
            sort(it.second.begin(), it.second.end());  
        }

        vector<int>ans;
        for(auto& p:points){
            int x=p[1],y=p[0],count=0;
            auto it=mp.lower_bound(x);
            for(;it!=mp.end();it++){
                auto& heights=it->second;
                count+=(heights.end()-lower_bound(heights.begin(),heights.end(),y));
            }

            ans.push_back(count);
        }

        return ans;
    }
};