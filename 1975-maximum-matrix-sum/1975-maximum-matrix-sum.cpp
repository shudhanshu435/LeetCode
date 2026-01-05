class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int cnt=0;
        long long sum=0;
        long long maxi=INT_MAX;
        int n=matrix.size();
        for(auto &i:matrix){
            for(auto &j:i){
                if(j<0)cnt++;
                sum+=abs(j);
                maxi=min(maxi,abs((long long)j));
            }
        }
        cout<<cnt<<endl;
        if(cnt&1)return sum-(2*maxi);
        return sum;
    }
};