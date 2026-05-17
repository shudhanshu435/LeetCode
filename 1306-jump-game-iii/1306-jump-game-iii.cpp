class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        queue<int>q;
        q.push(start);
        int n=arr.size();
        vector<bool>vis(50001,0);
        // vis[start]=1;
        while(!q.empty()){
            int t=q.front();
            q.pop();
            if(vis[t])continue;
            if(arr[t]==0)return 1;
            vis[t]=1;
            if(t-arr[t]>=0)q.push(t-arr[t]);
            if(t+arr[t]<n)q.push(t+arr[t]);
        }
        return 0;
    }
};