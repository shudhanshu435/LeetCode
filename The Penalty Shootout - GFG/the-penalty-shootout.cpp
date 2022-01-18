// { Driver Code Starts
 
#include <bits/stdc++.h>
using namespace std;



 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	
	int penaltyScore(string S)
	{
	    // Your code goes here
	    int count=0;
	    for(int i=1;i<S.length();i++){
	        if(S[i]=='1'&&S[i-1]=='2')count++;
	    }
	    return count;
	}
};

// { Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string S;
   		cin >> S;

   	    Solution ob;

   		cout << ob.penaltyScore(S) << "\n";
   	}

    return 0;
}  // } Driver Code Ends