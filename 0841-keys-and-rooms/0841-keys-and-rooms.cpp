class Solution {
public:
    void dfs(int k, vector<vector<int>>& rooms, vector<bool>&vis){
        vis[k]=1;
        for(auto i:rooms[k]){
            if(!vis[i]){
                dfs(i,rooms,vis);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        vector<bool>vis(n,0);
        dfs(0,rooms,vis);
        for(auto i:vis)if(!i)return 0;
        return 1;
    }
};