class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& res) {
        unordered_map<int,vector<int>>mp;
        for(auto i:res){
            int u=i[0];
            int v=i[1];
            mp[u].push_back(v);
        }
        int cnt=0;
        for(auto &[a,b]:mp){
            vector<int>vv(11,0);
            for(auto i:b)vv[i]=1;
            if(vv[2]!=0 or vv[3]!=0){
                if(vv[4]==0 and vv[5]==0 and vv[6]==0 and vv[7]==0)cnt++;
                else if(vv[6]==0 and vv[7]==0 and vv[8]==0 and vv[9]==0)cnt++;
            } 
            else {
                if(vv[6]==0 and vv[7]==0 and vv[8]==0 and vv[9]==0)cnt++;
                if(vv[2]==0 and vv[3]==0 and vv[4]==0 and vv[5]==0)cnt++;
            }
        }
        cnt+=(n-mp.size())*2;


        return cnt;
    }
};