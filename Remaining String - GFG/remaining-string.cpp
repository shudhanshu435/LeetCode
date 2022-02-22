// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	
	string printString(string &S, char ch, int count)
	{
	    // Your code goes here
	    string ss="Empty string";
	    if(count==0)return S;
	    int cnt=0;
	    for(int i=0;i<S.length();i++){
	        if(S[i]==ch)cnt++;
	        if(cnt==count){
	            if(i==S.length()-1)continue;
	            else {
	                ss.clear();
	                ss=S.substr(i+1,S.length()-1);
	            }
	            break;
	        }
	    }
	    return ss;
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
   		string s;
   		char ch;
   		int count;

   		cin >> s >> ch >> count;
   		Solution ob;
   		cout << ob.printString(s, ch, count) << "\n";
   		
   	}

    return 0;
}  // } Driver Code Ends