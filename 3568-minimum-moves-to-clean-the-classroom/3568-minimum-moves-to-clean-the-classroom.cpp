class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int n=classroom.size();
        int m=classroom[0].size();

        int sr,sc;
        int litterCount=0;

        vector<vector<int>> id(n,vector<int>(m,-1));

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(classroom[i][j]=='S'){
                    sr=i;
                    sc=j;
                }
                if(classroom[i][j]=='L'){
                    id[i][j]=litterCount++;
                }
            }
        }

         int fullMask = (1<<litterCount)-1;

         queue<array<int,4>> q;

        vector<vector<vector<vector<bool>>>> visited(n,vector<vector<vector<bool>>>(m,vector<vector<bool>>(energy + 1,vector<bool>(1 << litterCount, false))));

         q.push({sr,sc,energy,0});
         visited[sr][sc][energy][0]=true;

         int row[]={0,0,-1,1};
         int col[]={-1,1,0,0};

         int moves=0;

         while(!q.empty()){
            int size=q.size();
            while(size--){
                auto [r,c,e,mask]=q.front();
                q.pop();

                if(mask==fullMask){
                    return moves;
                }

               for(int k=0; k<4; k++){
                int nr=r+row[k];
                int nc=c+col[k];

                if(nr<0 || nr>=n || nc<0 || nc>=m){
                    continue;
                }

                if(classroom[nr][nc]=='X'){
                    continue;
                }

                if(e==0){
                    continue;
                }

                int ne=e-1;
                int nmask=mask;

                if(classroom[nr][nc]=='L'){
                    nmask|=(1<<id[nr][nc]);
                }

                if(classroom[nr][nc]=='R'){
                    ne=energy;
                }

                if(classroom[nr][nc]=='R'){
                    ne=energy;
                }
                 if(!visited[nr][nc][ne][nmask]){
                    visited[nr][nc][ne][nmask]=true;
                    q.push({nr,nc,ne,nmask});
                 }
               } 

            }
            moves++;
        }
        return -1;
    }
};