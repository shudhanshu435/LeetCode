class Solution {
public:
    int gpp;
    map<pair<int,int>,int>mp;
    int solve(int i, int maxi, vector<pair<int,int>>&range){
        if(i>=range.size()){
            if(maxi>=gpp)return 0;
            else return 1e9;
        }

        if(range[i].first>maxi)return 1e9;

        if(mp.find({i,maxi})!=mp.end())return mp[{i,maxi}];

        int nop=solve(i+1,maxi,range);
        int op=1+solve(i+1, max(maxi, range[i].second), range);

        return mp[{i,maxi}]=min(nop,op);
    }
    int minTaps(int n, vector<int>& ranges) {
        gpp=n;
        vector<pair<int,int>>range;
        for(int i=0;i<ranges.size();i++){
            int start = max(0, i-ranges[i]);
            int end = min(n,i+ranges[i]);

            range.push_back({start,end});
        }
        sort(begin(range),end(range));
        int res=solve(0,0,range);

        return res==1e9?-1:res;

    }
};