class Solution {
public:
    const int MOD=1e9+7;
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n=board.size();
        vector<vector<int>>vec(n,vector<int>(n,0));
        vector<vector<int>>way(n,vector<int>(n,0));
        way[0][0]=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]>='0' and board[i][j]<='9'){
                    vec[i][j]=board[i][j]-'0';
                }
                else vec[i][j]=-1;
            }
        }
        vec[0][0]=0;
        vec[n-1][n-1]=0;
        bool b=0;
        for(int i=0;i<n;i++){
            if(vec[0][i]==-1)b=1;
            else if(b)vec[0][i]=-1;
            else if(i)vec[0][i]+=vec[0][i-1];
            if(vec[0][i]!=-1 and i)way[0][i]=way[0][i-1];
        }
        b=0;
        for(int i=0;i<n;i++){
            if(vec[i][0]==-1)b=1;
            else if(b)vec[i][0]=-1;
            else if(i)vec[i][0]+=vec[i-1][0];
            if(vec[i][0]!=-1 and i)way[i][0]=way[i-1][0];
        }

        for(int i=1;i<n;i++){
            for(int j=1;j<n;j++){
                if(vec[i][j]==-1)continue;
                int best=max({vec[i-1][j],vec[i-1][j-1],vec[i][j-1]});
                if(best==-1){
                    vec[i][j]=-1;continue;
                }
                vec[i][j]+=best;
                if(vec[i-1][j]==best)way[i][j]=(way[i][j]+way[i-1][j])%MOD;
                if(vec[i-1][j-1]==best)way[i][j]=(way[i][j]+way[i-1][j-1])%MOD;
                if(vec[i][j-1]==best)way[i][j]=(way[i][j]+way[i][j-1])%MOD;
            }
        }

        if(vec[n-1][n-1]==-1)return {0,0};
        return {vec[n-1][n-1],way[n-1][n-1]};

        // for(int i=0;i<n;i++){
        //     for(int j=0;j<n;j++){
        //         cout<<vec[i][j]<<' ';
        //     }
        //     cout<<endl;
        // }
        
    }
};