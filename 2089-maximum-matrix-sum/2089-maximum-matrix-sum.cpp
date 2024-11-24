class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        long long sum=0;
        int neg=0,z=0;
        int mini=INT_MAX;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]<0){
                    neg++;
                }
                mini=min(mini,abs(matrix[i][j]));
                if(matrix[i][j]==0)z++;
                sum+=abs(matrix[i][j]);
            }
        }
        if(z)return sum;
        if(neg&1)sum=sum-mini-mini;
        return sum;
    }
};