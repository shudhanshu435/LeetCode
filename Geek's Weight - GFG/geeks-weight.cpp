// { Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution{
	public:
   	long long int total_Money(int n, int k){
   	    // Code here.
   	    long long int s=n/k;
        long long int sum=k*(s*(s+1)/2);
   	    return sum;
   	}    
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, k;
		cin >> n >> k;
		Solution ob;
		long long int ans = ob.total_Money(n, k);
		cout << ans <<"\n";
	}  
	return 0;
}  // } Driver Code Ends