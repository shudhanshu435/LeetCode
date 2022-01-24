// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

/*  Function to calculate the longest consecutive ones
*   N: given input to calculate the longest consecutive ones
*/
class Solution
{
public:
    int maxConsecutiveOnes(int N)
    {
        // code here
        int cnt1 = 0, m = 0;
        while (N)
        {
            int t = N & 1;
            if (t == 1)cnt1++;
            else 
            {
                m=max(m,cnt1);
                cnt1 = 0;
            }
            N >>= 1;
        }
        m=max(m,cnt1);
        return m;
    }
};

// { Driver Code Starts.

// Driver Code
int main() {
	int t;
	cin>>t;//testcases
	while(t--)
	{
		int n;
		cin>>n;//input n
		Solution obj;
		//calling maxConsecutiveOnes() function
		cout<<obj.maxConsecutiveOnes(n)<<endl;
	}
	return 0;
}  // } Driver Code Ends