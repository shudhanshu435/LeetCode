//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{   
public:

    int res;
    vector<vector<bool>> indian, arabian;
    void dfs(int i, int j, vector<vector<int>> &mat, vector<vector<bool>>&vis){
        if(vis[i][j]) return;
        vis[i][j] = true;
        if(arabian[i][j] && indian[i][j]) res+=1;
        if(i + 1 <  mat.size() && mat[i + 1][j] >= mat[i][j]) dfs(i + 1, j, mat, vis);  //down
        if(i - 1 >= 0 && mat[i - 1][j] >= mat[i][j]) dfs(i - 1, j, mat, vis);  //up
        if(j + 1 <  mat[0].size() && mat[i][j + 1] >= mat[i][j]) dfs(i, j + 1, mat, vis);  //left
        if(j - 1 >= 0 && mat[i][j - 1] >= mat[i][j]) dfs( i, j - 1, mat, vis);   //right
        
    }
    int water_flow(vector<vector<int>> &mat,int N,int M){
    // Write your code here.
        res = 0;
        indian = arabian = vector<vector<bool>>(N, vector<bool>(M, false));
        for(int i=0;i<N;i++){
            dfs(i,0,mat,indian);
            dfs(i,M-1,mat,arabian);
        }
        for(int j=0;j<M;j++){
            dfs(0,j,mat,indian);
            dfs(N-1,j,mat,arabian);
        }
        return res;
    }
};



//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<vector<int>> mat(n, vector<int>(m));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin>>mat[i][j];
            }
        }
        Solution ob;
        cout << ob.water_flow(mat, n, m) << endl;
        
    }
}


// } Driver Code Ends