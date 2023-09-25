//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{   
    public: 
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
    {
        // code here 
        vector<int>vec;
        int left=0,right=c-1,top=0,bottom=r-1;
        while(left<=right && top<=bottom){
            for(int i=left;i<=right;i++)vec.push_back(matrix[top][i]);
            top++;
            if(top<=bottom){
                for(int i=top;i<=bottom;i++)vec.push_back(matrix[i][right]);
                right--;
            }
            else break;
            if(right>=left){
                for(int i=right;i>=left;i--)vec.push_back(matrix[bottom][i]);
                bottom--;
            }
            else break;
            if(bottom>=top){
                for(int i=bottom;i>=top;i--)vec.push_back(matrix[i][left]);
                left++;
            }
            else break;
        }
        return vec;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int r,c;
        cin>>r>>c;
        vector<vector<int> > matrix(r); 

        for(int i=0; i<r; i++)
        {
            matrix[i].assign(c, 0);
            for( int j=0; j<c; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends