//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    int mod = 1000000007;
    long long reqans(long long int r)
    {
        if (r == 1)
        return 1;
        return (mod - ((mod / r) * reqans(mod % r)) % mod + mod) % mod;
    }
    int compute_value(int n)
    {
        // Code here
        long long int res = 1, nCr = 1;
        for (int i = 1; i <= n; i++)
        {
            nCr = (((nCr * (n + 1 - i)) % mod) * reqans(i)) % mod;
            res = (res + (nCr * nCr) % mod) % mod;
        }
        return res % mod;
    }
};


//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution ob;
		int ans = ob.compute_value(n);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends