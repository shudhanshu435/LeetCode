class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();

        vector<vector<pair<int,int>>>rows(m,vector<pair<int,int>>(n,{0,0}));
        vector<vector<pair<int,int>>>cols(m,vector<pair<int,int>>(n,{0,0}));
        vector<vector<pair<int,int>>>aaa(m,vector<pair<int,int>>(n,{0,0}));
        // X X
        // X Y

        int ans=0;
        for(int i=0;i<m;i++){
            int x=0,y=0;
            for(int j=0;j<n;j++){
                if(grid[i][j]=='X')x++;
                else if(grid[i][j]=='Y') y++;
                rows[i][j]={x,y};
            }

        }
        // cout<<"rows"<<endl;
        // for(auto i:rows){
        //     for(auto v:i){
        //         cout<<v.first<<" "<<v.second<<"   ";
        //     }
        //     cout<<endl;
        // }

        for(int i=0;i<n;i++){
            int x=0,y=0;
            for(int j=0;j<m;j++){
                if(grid[j][i]=='Y')y++;
                else if(grid[j][i]=='X') x++;
                cols[j][i]={x,y};
            }
        }

        // cout<<"cols"<<endl;
        // for(auto i:cols){
        //     for(auto v:i){
        //         cout<<v.first<<" "<<v.second<<"   ";
        //     }
        //     cout<<endl;
        // }

        for(int i=0;i<m;i++){
            int x=0,y=0;
            for(int j=0;j<n;j++){
                x=rows[i][j].first+cols[i][j].first;
                y=rows[i][j].second+cols[i][j].second;
                if(grid[i][j]=='X')x--;
                else if(grid[i][j]=='Y') y--;
                if(i-1>=0 and j-1>=0){
                    x+=aaa[i-1][j-1].first;
                    y+=aaa[i-1][j-1].second;
                }
                if(x==y and x!=0)ans++;
                aaa[i][j]={x,y};
            }
        }



        return ans;

    }
};