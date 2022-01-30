// { Driver Code Starts

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution{
	public:
	string digitsNum(int N)
	{
	    // Code here.
	    string s="";
	    if(N<10){
	        string ss=to_string(N);
	        s+=ss;
	    }
	    else{
	        int m=N/9;
	        int g=N%9;
	        if(g!=0){
	        string ss=to_string(g);
	        s+=ss;}
	        while(m--)s+='9';
	    }
	    while(N--)s+='0';
	    return s;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution ob;
		string ans = ob.digitsNum(n);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends