class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int>a(n,0),b(n,0);
        for(auto i:trust){
            a[i[0]-1]++;  //outdegree
            b[i[1]-1]++;  //indegree
        }
        for(int i=0;i<n;i++){
            if(a[i]==0 and b[i]==n-1)return i+1;
        }
        return -1;
    }
};