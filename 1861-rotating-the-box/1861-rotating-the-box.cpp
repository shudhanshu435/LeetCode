class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& bg) {
        int n=bg.size();
        int m=bg[0].size();
        for(auto &i:bg){
            int l=m-1,r=m-1;
            while(l>=0){
                if(i[l]=='*'){
                    r=l-1;
                }
                else if(i[l]=='#'){
                    swap(i[l],i[r]);
                    r--;
                }
                l--;
            }
        }
        vector<vector<char>>v(m,vector<char>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                v[i][j]=bg[j][i];
            }
        }
        for(auto &i:v){
            reverse(i.begin(),i.end());
        }
        return v;
    }
};