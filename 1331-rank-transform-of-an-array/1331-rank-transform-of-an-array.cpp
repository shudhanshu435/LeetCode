class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int>v=arr;
        unordered_map<int,int>mp;
        sort(v.begin(),v.end());
        int n=v.size();
        if(n==0)return {};
        int k=1;
        mp[v[0]]=k;
        for(int i=1;i<n;i++){
            if(v[i]==v[i-1])continue;
            mp[v[i]]=++k;
        }
        vector<int>ans;
        for(auto i:arr){
            ans.push_back(mp[i]);
        }
        return ans;
    }
};

/*
40, 10, 20, 30
0   1   2   3

10 20 30 40
1  2  3  0

*/