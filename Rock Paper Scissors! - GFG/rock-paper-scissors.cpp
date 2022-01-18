// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
  public:
    string gameResult (string s)
        {
            //code here.
            if(s[0]==s[1])return "DRAW";
            else{
                if((s[0]=='S'&&s[1]=='P')||(s[0]=='R'&&s[1]=='S')||(s[0]=='P'&&s[1]=='R'))return "A";
                else return "B";
            }
        }
};

// { Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout <<ob.gameResult (s) << endl;
    }
}

// Contributed By: Pranay Bansal
  // } Driver Code Ends