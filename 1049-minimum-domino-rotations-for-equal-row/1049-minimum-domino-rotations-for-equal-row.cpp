class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int n=tops.size(),j,ans=INT_MAX;
        for(int i=1;i<=6;i++){
            int cnt=0;
            for(j=0;j<n;j++){
                if(tops[j]!=i){
                    if(bottoms[j]==i)cnt++;
                    else break;
                }
            }
            if(j==n){
                ans=min(ans,cnt);
            }
        }

        for(int i=1;i<=6;i++){
            int cnt=0;
            for(j=0;j<n;j++){
                if(bottoms[j]!=i){
                    if(tops[j]==i)cnt++;
                    else break;
                }
            }
            if(j==n){
                ans=min(ans,cnt);
            }
        }
        if(ans==INT_MAX)return -1;
        return ans;
    }
};