class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& rr) {
        sort(rr.begin(),rr.end());
        rr.insert(rr.begin(),{1,0});
        rr.push_back({n,n-1});
        // for(auto i:rr)cout<<i[0]<<i[1]<<endl;
        int m=rr.size();
        for(int i=1;i<m;i++){
            rr[i][1]=min(rr[i-1][1]+rr[i][0]-rr[i-1][0],rr[i][1]);
        }
        for(int i=m-2;i>=0;i--){
            rr[i][1]=min(rr[i+1][1]-rr[i][0]+rr[i+1][0],rr[i][1]);
        }

        int ans=0;
        for(int i=1;i<m;i++){
            ans=max(ans,max(rr[i-1][1],rr[i][1])+((rr[i][0]-rr[i-1][0])-abs(rr[i][1]-rr[i-1][1]))/2);
        }


        return ans;
    }
};