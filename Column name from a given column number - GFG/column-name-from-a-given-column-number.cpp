//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
    public:
    string colName (long long int n)
    {
        // your code here
        string s="";
        while(n>26){
            if(n%26==0){
                s+='Z';
                n=(n/26)-1;
            }
            else{
                s+='A'+(n%26)-1;
                n=(n/26);
            }
        }
        s+='A'+n-1;
        reverse(s.begin(),s.end());
        return s;
    }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
	{
		long long int n; cin >> n;
		Solution ob;
		cout << ob.colName (n) << '\n';
	}
}

// } Driver Code Ends