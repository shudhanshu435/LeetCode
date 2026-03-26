class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        // for horizontal cut
        unordered_map<long long,int>mp1,mp2;
        int m=grid.size();
        int n=grid[0].size();
        long long tot=0;
        for(auto i:grid){
            for(auto j:i){
                mp2[j]=1;
                tot+=j;
            }
        }
        if(m==1){
            long long curr=0;
            for(int i=0;i<n;i++){
                curr+=grid[0][i];
                if(curr==tot-curr)return 1;
                if(curr<tot-curr){
                    if(curr==tot-curr-grid[0][i+1] or curr==tot-curr-grid[0][n-1])return 1;
                }
                if(curr>tot-curr){
                    if(curr-grid[0][0]==tot-curr or curr-grid[0][i]==tot-curr)return 1;
                }
            }
            return 0;
        }
        if(n==1){
            long long curr=0;
            for(int i=0;i<m;i++){
                curr+=grid[i][0];
                if(curr==tot-curr)return 1;
                if(curr<tot-curr){
                    if(curr==tot-curr-grid[i+1][0] or curr==tot-curr-grid[m-1][0])return 1;
                }
                if(curr>tot-curr){
                    if(curr-grid[0][0]==tot-curr or curr-grid[i][0]==tot-curr)return 1;
                }
            }
            return 0;
        }
        long long curr=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                curr+=grid[i][j];
                mp1[grid[i][j]]++;
                mp2[grid[i][j]]--;
                if(mp2[grid[i][j]]==0){
                    mp2.erase(grid[i][j]);
                }
            }
            long long nsum=tot-curr;
            if(curr==nsum)return 1;
            if(curr<nsum){
                if(m-1-i==1){
                    if(nsum-grid[i+1][0]==curr or nsum-grid[i+1][n-1]==curr)return 1;
                }
                else if(mp2[nsum-curr]>0)return 1;
            }
            if(curr>nsum){
                if(i==0){
                    if(curr-grid[0][0]==nsum or curr-grid[0][n-1]==nsum)return 1;
                }
                else if(mp1[curr-nsum]>0)return 1;
            }
        }

        // for vertical cut
        curr=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                curr+=grid[j][i];
                mp2[grid[j][i]]++;
                mp1[grid[j][i]]--;
                if(mp1[grid[j][i]]==0){
                    mp1.erase(grid[j][i]);
                }
            }

            long long nsum=tot-curr;
            if(curr==nsum)return 1;
            if(curr<nsum){
                if(n-1-i==1){
                    if(nsum-grid[0][n-1]==curr or nsum-grid[m-1][n-1]==curr)return 1;
                }
                else if(mp1[nsum-curr]>0)return 1;
            }
            if(curr>nsum){
                if(i==0){
                    if(curr-grid[0][0]==nsum or curr-grid[m-1][0]==nsum)return 1;
                }
                else if(mp2[curr-nsum]>0)return 1;
            }
        }

        return 0;
    }
};