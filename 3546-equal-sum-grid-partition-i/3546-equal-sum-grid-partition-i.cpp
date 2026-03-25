class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        //for vertical cut
        vector<long long>vec;
        long long tot=0;
        for(auto i:grid){
            long long sum=0;
            for(auto j:i){
                sum+=j;
            }
            vec.push_back(sum);
            tot+=sum;
        }
        long long curr=0;
        for(auto i:vec){
            curr+=i;
            if(tot-curr==curr)return 1;
        }

        // for horizontal cut
        vector<long long>tec;
        tot=0;
        for(int i=0;i<grid[0].size();i++){
            long long sum=0;
            for(int j=0;j<grid.size();j++){
                sum+=grid[j][i];
            }
            tec.push_back(sum);
            tot+=sum;
        }
        curr=0;
        for(auto i:tec){
            curr+=i;
            if(tot-curr==curr)return 1;
        }

        return 0;

    }
};