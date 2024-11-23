class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int m=box.size();
        int n=box[0].size();

        vector<vector<char>>vec(n, vector<char>(m));
        //transpose
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                vec[i][j]=box[j][i];
            }
        }

        //90 degree rotate
        for(vector<char>& row: vec){
            reverse(row.begin(),row.end());
        }

        for(int j=0;j<m;j++){
            int space=n-1;
            for(int i=n-1;i>=0;i--){
                if(vec[i][j]=='*'){
                    space=i-1;
                    continue;
                }
                if(vec[i][j]=='#'){
                    vec[i][j]='.';
                    vec[space][j]='#';
                    space--;
                }
            }
        }

        // for(int j=0;j<m;j++){
        //     for(int i=n-1;i>=0;i--){
        //         if(vec[i][j]=='.'){
        //             int row=-1;
        //             for(int k=i-1;k>=0;k--){
        //                 if(vec[k][j]=='*'){
        //                     break;
        //                 } else if(vec[k][j]=='#'){
        //                     row=k;
        //                     break;
        //                 }
        //             }
        //             if(row!=-1){
        //                 vec[i][j]='#';
        //                 vec[row][j]='.';
        //             }
        //         }
        //     }
        // }
        return vec;
    }
};