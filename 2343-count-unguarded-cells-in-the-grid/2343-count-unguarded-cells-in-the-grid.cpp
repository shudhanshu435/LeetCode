class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>>visited(m, vector<int>(n,0));
        for(auto v:guards){
            int l=v[0];
            int r=v[1];
            visited[l][r]=2;
        }
        for(auto v:walls){
            int l=v[0];
            int r=v[1];
            visited[l][r]=3;
        }

        for(auto v:guards){
            int i=v[0],j=v[1];
            
            int a=i-1;
            int b=j;
            while(a>=0){
                if(visited[a][b]==0)visited[a][b]=1;
                else if(visited[a][b]==2 or visited[a][b]==3)break;
                a--;
            }

            a=i+1;
            b=j;
            while(a<m){
                if(visited[a][b]==0)visited[a][b]=1;
                else if(visited[a][b]==2 or visited[a][b]==3)break;
                a++;
            }

            a=i;
            b=j-1;
            while(b>=0){
                if(visited[a][b]==0)visited[a][b]=1;
                else if(visited[a][b]==2 or visited[a][b]==3)break;
                b--;
            }

            a=i;
            b=j+1;
            while(b<n){
                if(visited[a][b]==0)visited[a][b]=1;
                else if(visited[a][b]==2 or visited[a][b]==3)break;
                b++;
            }

        }

        int cnt=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(visited[i][j]==0)cnt++;
            }
        }
        return cnt;
    }
};