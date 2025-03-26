class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        long long sum=0;
        int ev=0;
        int m=grid.size();
        int n=grid[0].size();
        unordered_map<int,bool>mp;
        vector<int>v;
        for(auto g:grid){
            for(auto i:g){
                v.push_back(i);
                mp[i%x]=1;
            }
        }
        if(mp.size()>=2)return -1;
        sort(v.begin(),v.end());
        int s=v.size();
        int ans=0;
        int mid=v[s/2];
        cout<<mid<<endl;
        for(int i=0;i<s;i++){
            ans+=abs(v[i]-mid)/x;
        }
        return ans;
        
    }
};