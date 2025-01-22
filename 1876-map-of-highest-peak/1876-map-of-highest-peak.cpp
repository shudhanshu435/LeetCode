class Solution {
public:
    #define pp pair<int,pair<int,int>>
    vector<vector<int>> highestPeak(vector<vector<int>>& iss) {
        int m=iss.size();
        int n=iss[0].size();
        priority_queue<pp,vector<pp>,greater<pp>>pq;
        vector<vector<int>>vec(m, vector<int>(n,0));
        vector<vector<int>>vis(m, vector<int>(n,false));

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(iss[i][j]==1){
                    pq.push({0,{i,j}});
                    vis[i][j]=true;
                }
            }
        }
        while(!pq.empty()){
            int val=pq.top().first;
            int ii=pq.top().second.first;
            int jj=pq.top().second.second;
            pq.pop();
            
            if(ii-1>=0 and vis[ii-1][jj]==false){
                vis[ii-1][jj]=true;
                vec[ii-1][jj]=val+1;
                pq.push({val+1,{ii-1,jj}});
            }
            if(jj-1>=0 and vis[ii][jj-1]==false){
                vis[ii][jj-1]=true;
                vec[ii][jj-1]=val+1;
                pq.push({val+1,{ii,jj-1}});
            }
            if(ii+1<m and vis[ii+1][jj]==false){
                vis[ii+1][jj]=true;
                vec[ii+1][jj]=val+1;
                pq.push({val+1,{ii+1,jj}});
            }
            if(jj+1<n and vis[ii][jj+1]==false){
                vis[ii][jj+1]=true;
                vec[ii][jj+1]=val+1;
                pq.push({val+1,{ii,jj+1}});
            }

        }
        return vec;
    }
};