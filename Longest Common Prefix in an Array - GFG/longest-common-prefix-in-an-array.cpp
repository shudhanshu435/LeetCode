//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    
    string longestCommonPrefix (string arr[], int N)
    {
        // your code here
        string ans="";
        int cnt=0;
        for(int i=0;i<arr[0].length();i++){
            char s=arr[0][i];
            cnt=0;
            for(int j=0;j<N;j++){
                if(arr[j][i]==s)cnt++;
                else break;
            }
            if(cnt!=N){
                break;
            }
            else ans+=s;
        }
        if(ans.length()==0)return "-1 ";
        return ans;
        
    }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        string arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        
        Solution ob;
        cout << ob.longestCommonPrefix (arr, n) << endl;
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends