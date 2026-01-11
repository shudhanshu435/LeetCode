class Solution {
public: // 3 1 3 2 2 
    vector<int>prevSmall(vector<int>&v){
        stack<int>s;
        int n=v.size();
        vector<int>vv;
        for(int i=0;i<n;i++){
            while(!s.empty() and v[s.top()]>=v[i]){
                s.pop();
            }
            if(s.empty())vv.push_back(-1);
            else vv.push_back(s.top());
            s.push(i);
        }
        return vv;
    }
    vector<int>nextSmall(vector<int>&v){
        stack<int>s;
        int n=v.size();
        vector<int>vv(n);
        for(int i=n-1;i>=0;i--){
            while(!s.empty() and v[s.top()]>=v[i]){
                s.pop();
            }
            if(s.empty())vv[i]=n;
            else vv[i]=s.top();
            s.push(i);
        }
        return vv;
    }
    int maxHisto(vector<int>&v){
        vector<int>v1=prevSmall(v);
        vector<int>v2=nextSmall(v);
        // for(auto i:v1)cout<<i<<" ";
        // cout<<endl;
        // for(auto i:v2)cout<<i<<" ";
        // cout<<endl;
        int ans=0;
        int n=v.size();
        for(int i=0;i<n;i++){
            ans=max(ans,(v2[i]-v1[i]-1)*v[i]);
        }
        return ans;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<int>v(m,0);
        int res=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]=='0')v[j]=0;
                else v[j]+=1;
            }
            // for(auto &ii:v)cout<<ii<<" ";
            // cout<<endl;
            res=max(res,maxHisto(v));
        }
        return res;
    }
};