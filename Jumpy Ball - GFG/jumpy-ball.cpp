// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function Template for C++
class Solution
{
public:
    long long jumpyBall(long long N)
    {
        // Write Your Code here
        long long int cnt=0;
        while(N){
            cnt=cnt+(2*N);
            N/=2;
        }return cnt;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long N;
        cin>>N;
        Solution ob;
        long long ans  = ob.jumpyBall(N);
        cout<<ans<<endl;
    }
    return 0;
}  // } Driver Code Ends