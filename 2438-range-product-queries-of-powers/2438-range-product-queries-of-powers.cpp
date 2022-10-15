class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int>vec,ans;
        int pw=1;
        while(n){
            if(n&1)
                vec.push_back(pw);
            pw*=2;
            n/=2;
        }
        sort(vec.begin(),vec.end());
        int sz=queries.size();
        long long mul=1;
        for(int i=0;i<sz;i++){
            mul=1;
            for(int j=queries[i][0];j<=queries[i][1];j++){
                mul=((mul%1000000007)*(vec[j]%1000000007))%1000000007;
            }
            ans.push_back(mul);
        }
        return ans;
    }
};