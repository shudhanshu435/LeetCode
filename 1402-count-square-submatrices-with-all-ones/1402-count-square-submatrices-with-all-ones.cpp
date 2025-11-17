class Solution {
public:
    int maxi(vector<int>&v, int m){
        int maxx=0,one=0,ans=0;
        for(auto &i:v){
            if(i==1)one++;
            else{
                maxx=max(maxx,one);
                if(one>=m)ans+=one-m+1;
                one=0;
            }
        }
        if(one>=m)ans+=one-m+1;
        return ans;
    }
    int countSquares(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        int ans=0;
        for(int i=0;i<n;i++){
            vector<int>v(mat[i].begin(),mat[i].end());
            ans+=maxi(v,1);
            for(int j=i+1;j<n;j++){
                for(int k=0;k<m;k++){
                    v[k]=v[k] & mat[j][k];
                }
                ans+=maxi(v,j-i+1);
            }
        }
        return ans;
    }
};