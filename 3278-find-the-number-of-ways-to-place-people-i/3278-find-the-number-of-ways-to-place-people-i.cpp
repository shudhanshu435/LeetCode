class Solution {
public:
/*
    [2,6],[4,4],[6,2]
*/
    int numberOfPairs(vector<vector<int>>& p){
        sort(p.begin(),p.end());
        for(auto i:p)cout<<i[0]<<" "<<i[1]<<endl;
        int cnt=0;
        for(int i=0;i<p.size();i++){
            for(int j=0;j<p.size();j++){
                if(i!=j and p[i][0]<=p[j][0] and p[i][1]>=p[j][1]){
                    bool b=1;
                    for(int k=0;k<p.size();k++){
                        if(i!=j and j!=k and i!=k and p[k][0]>=p[i][0] and p[k][0]<=p[j][0] and p[k][1]<=p[i][1] and p[k][1]>=p[j][1]){
                            b=0;
                            break;
                        }
                    }
                    if(b)cnt++;
                }
            }
        }
        return cnt;
    }
};