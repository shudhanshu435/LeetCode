// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:
	
	int binaryPalin (long long int N)
	{
	    // Your Code Here
	    string s="";
	    while(N){
	        s+=N&1;
	        N>>=1;
	    }
	    int size=s.length();
	    for(int i=0;i<size/2;i++){
	        if(s[i]!=s[size-1-i])return 0;
	    }return 1;
	}
};

// { Driver Code Starts.

int main()
{
	int t; cin >> t;
	while (t--)
	{
		long long int n; cin >> n;
		Solution ob;
		cout << ob.binaryPalin (n) << endl;
	}
}

// Contributed By: Pranay Bansal
  // } Driver Code Ends