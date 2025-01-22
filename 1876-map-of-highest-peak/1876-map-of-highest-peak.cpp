class Solution {
public:
    #define pp pair<int,pair<int,int>>
    vector<vector<int>> highestPeak(vector<vector<int>>& iss) {
        int m=iss.size();
        int n=iss[0].size();
        priority_queue<pp,vector<pp>,greater<pp>>pq;
        vector<vector<int>>vec(m, vector<int>(n,INT_MAX));
        int cnt=m*n;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(iss[i][j]==1){
                    pq.push({0,{i,j}});
                    cnt--;
                    vec[i][j]=0;
                }
            }
        }
        while(!pq.empty() and cnt){
            int val=pq.top().first;
            int ii=pq.top().second.first;
            int jj=pq.top().second.second;
            pq.pop();
            
            if(ii-1>=0 and vec[ii-1][jj]==INT_MAX){
                vec[ii-1][jj]=val+1;
                pq.push({val+1,{ii-1,jj}});
                cnt--;
            }
            if(jj-1>=0 and vec[ii][jj-1]==INT_MAX){
                vec[ii][jj-1]=val+1;
                pq.push({val+1,{ii,jj-1}});
                cnt--;
            }
            if(ii+1<m and vec[ii+1][jj]==INT_MAX){
                vec[ii+1][jj]=val+1;
                pq.push({val+1,{ii+1,jj}});
                cnt--;
            }
            if(jj+1<n and vec[ii][jj+1]==INT_MAX){
                vec[ii][jj+1]=val+1;
                pq.push({val+1,{ii,jj+1}});
                cnt--;
            }

        }
        return vec;
    }
};