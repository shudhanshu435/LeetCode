class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        // if(n==1)return 0;
        unordered_map<int,int>mp2;
        for(auto v:edges){
            mp2[v[1]]++;
        }
        int cnt=0,ans=0;
        for(int i=0;i<n;i++){
            if(mp2[i]==0){
                cnt++;
                ans=i;
                if(cnt>1)return -1;
            }
        }
        return ans;
    }
};