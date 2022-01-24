// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{
public:
    vector<int> getXor(vector<int> A, int N)
    {
        // Write your Code here
        int m=A[0];
        vector<int>vec;
        for(int i=1;i<N;i++)m=m^A[i];
        for(int i=0;i<N;i++){
            vec.push_back((m^A[i]));
        }return vec;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N ;
        vector<int> A(N);

        for (int i = 0; i < N; i++)
        {
            cin >> A[i];
        }

        Solution ob;
        vector<int> B = ob.getXor(A, N);
        for(int i = 0 ; i < N ; i++)
        {
            cout << B[i] <<" ";
        }
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends