// { Driver Code Starts
#include <iostream>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
        long long lucas(int n)
        {
            //code here.
            if(n==0)return 2;
            if(n==1)return 1;
            long long a = 2;
            long long b = 1;
            long long c;
            
            for(int i = 2; i <= n; i++)
            {
                c = (a + b) % 1000000007;
                
                a = b % 1000000007;
                b = c % 1000000007;
            }
            
            return c;
            }
        
};


// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		Solution ob;
		cout<<ob.lucas(n)<<endl;
	}
	return 0;
}  // } Driver Code Ends