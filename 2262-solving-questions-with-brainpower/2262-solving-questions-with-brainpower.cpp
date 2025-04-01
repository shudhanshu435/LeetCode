class Solution {
public:
    long long mostPoints(vector<vector<int>>& q) {
        int n=q.size();
        for(int i=n-2;i>=0;i--){
            if(i+q[i][1]+1<n)q[i][0]=max(q[i][0]+q[i+q[i][1]+1][0],q[i+1][0]);
            else q[i][0]=max(q[i+1][0],q[i][0]);
        }
        // for(auto i:vec)cout<<i<<" ";
        // cout<<endl;
        return q[0][0];
    }
};