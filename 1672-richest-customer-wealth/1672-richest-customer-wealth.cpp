class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int sum=0,sum1=0;
        int size=accounts.size();
        int len=accounts[0].size();
        for(int i=0;i<size;i++){
            sum=0;
            for(int j=0;j<len;j++){
                sum+=accounts[i][j];
            }
            sum1=max(sum,sum1);
        }return sum1;
    }
};