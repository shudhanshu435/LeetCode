class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        vector<pair<int,pair<int,int>>>vec;
        for(auto &t:tasks){
            vec.push_back({t[1]-t[0],{t[1],t[0]}});
        }
        sort(vec.rbegin(),vec.rend());
        int ans=0;
        // for(auto i:vec)cout<<i.first<<" "<<i.second.first<<" "<<i.second.second<<endl;
        ans+=vec[0].second.first;
        // cout<<ans<<endl;
        int left=vec[0].first;
        for(int i=1;i<vec.size();i++){
            int curr=vec[i].second.first - left;
            if(curr<0)curr=0;
            left=max(left, vec[i].second.first) - vec[i].second.second;
            ans+=curr;
            // cout<<ans<<endl;
        }

        return ans;
    }
};

// [[1,3],[2,4],[10,11],[10,12],[8,9]]
    //    2     2     1      2       1

    //    12+2+1+9+8 = 32
        // 3+2+10+7+10

    // 10,12    1,3  0,2    