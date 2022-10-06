class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int>vec(n+1, 0);
        for(int i=0; i<trust.size(); i++){
            vec[trust[i][1]]++; vec[trust[i][0]]--;}
        for(int i=1; i<n+1; i++)
            if(vec[i]==n-1)  return i;
        return -1;
    }
};