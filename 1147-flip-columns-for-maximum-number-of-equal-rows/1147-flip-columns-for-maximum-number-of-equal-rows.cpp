class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        unordered_map<string,int>mp;
        int n=matrix[0].size();
        for(auto v:matrix){
            string s="";
            s+="x";
            for(int i=1;i<n;i++){
                if(v[i]==v[i-1]){
                    if(s.back()=='x')s+="x";
                    else s+="y";
                }
                else{
                    if(s.back()=='x')s+="y";
                    else s+="x";
                }
            }
            mp[s]++;
        }
        int ans=0;
        for(auto i:mp)ans=max(ans,i.second);
        return ans;
    }
};