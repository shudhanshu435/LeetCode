class Solution {
public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
        int n=s.length();
        vector<vector<int>>vec(26, vector<int>(n+1,0));
        for(int i=0;i<26;i++){
            for(int j=1;j<=n;j++){
                if(s[j-1]==('a'+i))vec[i][j]=1+vec[i][j-1];
                else vec[i][j]=vec[i][j-1];
            }
        }
        // for(auto v:vec){
        //     for(auto i:v){
        //         cout<<i<<" ";
        //     }
        //     cout<<endl;
        // }
        vector<bool>v;
        for(auto q:queries){
            int l=q[0],r=q[1],k=q[2];
            int odd=0;
            for(int i=0;i<26;i++){
                if((vec[i][r+1]-vec[i][l])%2!=0)odd++;
            }

            if(odd==0)v.push_back(true);
            else {
                odd=odd/2;
                if(k>=odd)v.push_back(true);
                else v.push_back(false);
            }
        }

        return v;
    }
};