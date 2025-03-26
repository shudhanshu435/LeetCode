class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        // sort(logs.begin(),logs.end());
        // for(auto i:logs){
        //     cout<<i[0]<<","<<i[1]<<endl;
        // }
        int ans=0,pop=0;
        for(int i=1950;i<=2050;i++){
            int cnt=0;
            for(auto l:logs){
                if(i>=l[0] and i<=l[1]-1){
                    cnt++;
                }
            }
            // cout<<cnt<<endl;
            if(cnt>pop){
                ans=i;
                pop=cnt;
            }
        }
        // cout<<pop<<endl;
        return ans;
    }
};