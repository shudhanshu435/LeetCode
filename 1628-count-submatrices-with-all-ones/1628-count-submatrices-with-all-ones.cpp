class Solution {
public:
    int func(vector<int>&vec){
        int sum=0;
        int ans=0;
        for(int i=0;i<vec.size();i++){
            if(i==0)sum=vec[i];
            else if(vec[i]==0)sum=0;
            else sum=sum+vec[i];
            ans+=sum;
        }
        // cout<<sum<<endl;
        return ans;
    }
    int numSubmat(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        int res=0;
        vector<int>v;
        for(int i=0;i<m;i++){
            int k=i;
            v.clear();
            v.resize(n,1);
            // for(auto i:v)cout<<i<<" ";
            // cout<<endl;
            while(k<m){
                for(int j=0;j<n;j++){
                    v[j]=(v[j]&mat[k][j]);
                }
                // for(auto i:v)cout<<i<<" ";
                // cout<<endl;
                res+=func(v);
                k++;
            }
            // cout<<endl;
        }
        return res;
    }
};