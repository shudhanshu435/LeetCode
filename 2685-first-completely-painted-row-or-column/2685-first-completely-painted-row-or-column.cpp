class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        
        unordered_map<int,int>mp;
        for(int i=0;i<arr.size();i++){
            mp[arr[i]]=i;
        }
        int ans=INT_MAX;
        for(int i=0;i<n;i++){
            int maxi=-1;
            for(int j=0;j<m;j++){
                maxi=max(maxi,mp[mat[i][j]]);
            }
            ans=min(ans,maxi);
        }

        for(int i=0;i<m;i++){
            int maxi=-1;
            for(int j=0;j<n;j++){
                maxi=max(maxi,mp[mat[j][i]]);
            }
            ans=min(ans,maxi);
        }

        return ans;
    }
};