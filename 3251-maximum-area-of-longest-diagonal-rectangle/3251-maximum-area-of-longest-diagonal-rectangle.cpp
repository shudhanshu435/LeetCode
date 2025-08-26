#define sq(a) a*a
class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int ans=0;
        float diag=0;
        for(auto v:dimensions){
            if(sq(v[0])+sq(v[1]) > diag){
                ans=v[0]*v[1];
                diag=sq(v[0])+sq(v[1]);
            }
            else if(sq(v[0])+sq(v[1]) == diag){
                ans=max(ans,v[0]*v[1]);
            }
        }
        return ans;
    }
};