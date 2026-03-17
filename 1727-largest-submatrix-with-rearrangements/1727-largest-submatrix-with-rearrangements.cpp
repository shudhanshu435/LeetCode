class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        for(int i=0;i<n;i++){
            int cnt=0;
            for(int j=0;j<m;j++){
                if(matrix[j][i]==1){
                    cnt++;
                    matrix[j][i]=cnt;
                }
                else{
                    cnt=0;
                    matrix[j][i]=cnt;
                }
            }
        }
        int size=n;
        int ans=0;
        for(auto &i:matrix){
            sort(i.begin(),i.end());
            for(int j=0;j<n;j++){
                if(i[j]!=0){
                    ans=max(ans,i[j]*(n-j));
                }
            }
        }
        return ans;
    }
};