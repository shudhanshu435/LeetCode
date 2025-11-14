class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>>vec(n,vector<int>(n,0));
        for(int i=0;i<queries.size();i++){
            int a=queries[i][0],b=queries[i][2];
            int c=queries[i][1],d=queries[i][3];
            for(int j=a;j<=b;j++){
                vec[j][c]+=1;
                if(d+1<n)vec[j][d+1]-=1;
            }
        }
        for(int i=0;i<n;i++){
            for(int j=1;j<n;j++){
                vec[i][j]=vec[i][j-1]+vec[i][j];
            }
        }
        // for(auto i:vec){
        //     for(auto v:i)cout<<v<<" ";
        //     cout<<endl;
        // }
        return vec;
    }
};

// 1 1 0 0
// 1 2 1 0
// 0 1 1 0
// 0 0 0 0