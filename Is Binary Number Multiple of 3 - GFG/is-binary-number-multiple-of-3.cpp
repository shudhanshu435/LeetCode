// { Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
		
	int isDivisible(string s){
	    //complete the function here
	    long long int odd=0,even=0;
	    long long int len = s.length();
	    for(int i=0;i<len;i+=2){
	        if(s[i]=='1')even++;
	    }
	    for(int i=1;i<len;i+=2){
	        if(s[i]=='1')odd++;
	    }
	    long long int res=abs(even-odd);
	    if(res%3==0)return 1;
	    else return 0;
	}

};

// { Driver Code Starts.
int main(){
    
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        Solution ob;
        cout << ob.isDivisible(s) << endl;
    }
return 0;
}

  // } Driver Code Ends