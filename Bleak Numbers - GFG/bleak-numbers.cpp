// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
public:

    int countSetBits(int n){
        int cnt=0;
        while(n){
            n=n&(n-1);
            cnt++;
        }return cnt;
    }
	int is_bleak(int n)
	{
	    // Code here.
	    for(int i=n-1;i>=0;i--){
	        if(i + countSetBits(i) == n)return 0;
	    }return 1;
	}
};


// { Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	Solution ob;
    	int ans = ob.is_bleak(n);
    	cout << ans << "\n";
    }
	return 0;
}
  // } Driver Code Ends