//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    vector<int>polyMultiply(int Arr1[], int Arr2[], int M, int N)
    {
        // code here
        vector<int>ans(M+N,0);
        for(int i=0;i<M;i++){
            for(int j=0;j<N;j++){
                ans[i+j]+=Arr1[i]*Arr2[j];
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int M, N;
        cin >> M >> N;
        int Arr1[M], Arr2[N];
        for(int i=0;i<M;i++)cin>>Arr1[i];
        for(int i=0;i<N;i++)cin>>Arr2[i];
        Solution ob;
        vector<int>ans=ob.polyMultiply(Arr1,Arr2,M,N);
        for(int i=0;i<M+N-1;i++)cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends