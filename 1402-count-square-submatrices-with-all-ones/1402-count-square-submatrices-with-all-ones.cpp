class Solution {
public:
    int pos(vector<int>v, int k){
        int cnt=0,ans=0;
        for(int i=0;i<v.size();i++){
            if(v[i]==k)cnt++;
            else{
                if(cnt>=k)ans+=(cnt-k+1);
                cnt=0;
            }
        }
        if(cnt>=k)ans+=(cnt-k+1);
        return ans;
    }
    int countSquares(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        vector<int>v(n);
        int ans=0;
        for(int i=0;i<m;i++){
            int k=i;
            v.clear();
            v.resize(n,0);
            while(k<m){
                for(int j=0;j<n;j++){
                    v[j]+=mat[k][j];
                }
                // for(auto i:v)cout<<i<<" ";
                // cout<<endl;
                // cout<<k-i+1<<endl;
                int curr=pos(v,k-i+1);
                ans+=curr;
                k++;
            }
        }
        return ans;
    }
};