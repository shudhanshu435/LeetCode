class Solution {
public:
    int maxi(vector<int>&v){
        int maxx=0,one=0;
        for(auto &i:v){
            if(i==1)one++;
            else{
                maxx=max(maxx,one);
                one=0;
            }
        }
        return max(maxx,one);
    }
    int maximalSquare(vector<vector<char>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        int ans=0;
        vector<int>v;
        for(int i=0;i<n;i++){
            v.clear();
            for(auto &i:mat[i])v.push_back(i-'0');
            if(maxi(v)>=1)ans=max(ans,1*1);
            for(int j=i+1;j<n;j++){
                for(int k=0;k<m;k++){
                    v[k]=v[k] & (mat[j][k]-'0');
                }
                if(maxi(v)>=j-i+1)ans=max(ans,(j-i+1)*(j-i+1));
            }
        }
        return ans;
    }
};