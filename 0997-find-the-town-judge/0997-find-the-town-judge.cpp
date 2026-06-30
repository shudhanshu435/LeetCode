class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        unordered_map<int,int>mp;
        map<pair<int,int>,bool>mp2;
        for(auto i:trust){
            mp[i[0]-1]++;
            mp2[{i[0],i[1]}]=1;
        }
        int c=-1;
        for(int i=0;i<n;i++)if(mp[i]==0)c=i+1;
        if(c==-1)return -1;
        for(int i=1;i<n;i++){
            if(i!=c){
                if(!mp2[{i,c}])return -1;
            }
        }
        return c;
    }
};