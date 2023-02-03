//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    pair<int,int> endPoints(vector<vector<int>> matrix, int R, int C){
        //code here
        int i=0,j=0,d=0;
        while(i>=0 && i<R && j>=0 && j<C){
            if(!matrix[i][j]){
                if(d==0){
                    if(j<C-1)j++;
                    else break;
                }
                if(d==1){
                    if(i<R-1)i++;
                    else break;
                }
                if(d==2){
                    if(j>0)j--;
                    else break;
                }
                if(d==3){
                    if(i>0)i--;
                    else break;
                }
            }
            else{
                d=(d+1)%4;
                matrix[i][j]=0;
            }
        }
        pair<int,int> p(i,j);
        return p;
    }
};

//{ Driver Code Starts.


int main()
{
    int tc;
	scanf("%d", &tc);
	while(tc--){
		int row, col;
		scanf("%d", &row);
		scanf("%d", &col);
		vector<vector<int>> matrix(row , vector<int> (col));
	 
		for(int i = 0; i < row; i++){
			for(int j = 0; j < col; j++){
			    cin>>matrix[i][j];
			}
		}
		Solution obj;
		pair<int,int> p = obj.endPoints(matrix, row, col);
		
		cout << "(" << p.first << ", " << p.second << ")" << endl;
	}
	return 0;
}
// } Driver Code Ends