// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

 // } Driver Code Ends
   
class Solution
{
public:
    int isBitSet(int N)
    {
        // code here
        if(N==0)return 0;
        while (N)
        {
            if (N % 2 == 0)
            {
                return 0;
            }
            N /= 2;
        }
        
            return 1;
        
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        Solution ob;
        cout << ob.isBitSet(N) << endl;
    }
    return 0; 
}  // } Driver Code Ends