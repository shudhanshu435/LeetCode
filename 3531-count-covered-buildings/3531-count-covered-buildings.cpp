class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& bb) {
        unordered_map<int,set<int>>mpr;
        unordered_map<int,set<int>>mpc;
        for(int i=0;i<bb.size();i++){
            mpr[bb[i][0]].insert(bb[i][1]);
            mpc[bb[i][1]].insert(bb[i][0]);
        }
        int cnt=0;

        for(int i=0;i<bb.size();i++){
            if((mpr[bb[i][0]].size()>=2 and *mpr[bb[i][0]].begin()<bb[i][1] and *prev(mpr[bb[i][0]].end())>bb[i][1])
            and
            (mpc[bb[i][1]].size()>=2 and *mpc[bb[i][1]].begin()<bb[i][0] and *prev(mpc[bb[i][1]].end())>bb[i][0]))
            cnt++;
        }
        return cnt;
    }
};