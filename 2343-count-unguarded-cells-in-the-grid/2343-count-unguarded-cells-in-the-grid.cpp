class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>>vec(m,vector<int>(n,0));
        for(auto &i:guards)vec[i[0]][i[1]]=1;
        for(auto &i:walls)vec[i[0]][i[1]]=2;

        for(int i=0;i<m;i++){
            bool seen=false;
            for(int j=0;j<n;j++){
                if(vec[i][j]==1)seen=true;
                else if(vec[i][j]==2)seen=false;
                else if(seen)vec[i][j]=-1;
            }
            seen=false;
            for(int j=n-1;j>=0;j--){
                if(vec[i][j]==1)seen=true;
                else if(vec[i][j]==2)seen=false;
                else if(seen)vec[i][j]=-1;
            }
        }

        for(int i=0;i<n;i++){
            bool seen=false;
            for(int j=0;j<m;j++){
                if(vec[j][i]==1)seen=true;
                else if(vec[j][i]==2)seen=false;
                else if(seen)vec[j][i]=-1;
            }
            seen=false;
            for(int j=m-1;j>=0;j--){
                if(vec[j][i]==1)seen=true;
                else if(vec[j][i]==2)seen=false;
                else if(seen)vec[j][i]=-1;
            }
        }

        int cnt=0;
        for(auto i:vec){
            for(auto j:i){
                if(j==0)cnt++;
                cout<<j<<" ";
            }
            cout<<endl;
        }
        return cnt;

    }
};