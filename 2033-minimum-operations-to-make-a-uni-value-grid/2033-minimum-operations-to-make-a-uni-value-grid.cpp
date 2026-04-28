class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int m=grid.size();
        int n=grid[0].size();
        int sum=0;
        vector<int>v;
        for(auto i:grid){
            for(auto j:i){
                v.push_back(j);
            }
        }
        sort(v.begin(),v.end());
        n=v.size();
        int ans=0,ans2=0;
        if(n&1){
            int med=v[n/2];
            for(auto i:v){
                int diff=abs(i-med);
                if(diff%x!=0)return -1;
                ans+=diff/x;
            }
            return ans;
        }
        else{
            int f=v[(n/2)-1];
            for(auto i:v){
                int diff=abs(i-f);
                if(diff%x!=0)return -1;
                ans+=diff/x;
            }
            f=v[n/2];
            for(auto i:v){
                int diff=abs(i-f);
                if(diff%x!=0)return -1;
                ans2+=diff/x;
            }

            return min(ans,ans2);
        }

    }
};