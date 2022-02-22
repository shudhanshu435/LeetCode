// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

class Solution
{
  public:
    string stringFilter(string str) 
    { 
        //code here.
        string ss="";
        for(int i=1;i<=str.length();i++){
            if((str[i-1]=='a'&&str[i]=='c')||str[i-1]=='b'||(str[i-1]=='c'&&str[i-2]=='a'))
            continue;
            else ss+=str[i-1];
        }
        return ss;
    } 
};

// { Driver Code Starts.

int main() 
{
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string s;
   		cin >> s;
   		
   		Solution ob;
   		cout <<ob.stringFilter(s) << "\n";

   		
   	}

    return 0;
}  // } Driver Code Ends