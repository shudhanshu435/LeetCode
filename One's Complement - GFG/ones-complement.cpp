// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std; 

 // } Driver Code Ends
class Solution{
public:
    int onesComplement(int N){
        //code here
        string s="";
        while(N){
            int t=N&1;
            if(t==1)s+='0';
            else s+='1';
            N>>=1;
        }
        reverse(s.begin(),s.end());
        int res=stoi(s, 0, 2);
        return res;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        Solution ob;
        cout<<ob.onesComplement(n)<<"\n";
    }
}  // } Driver Code Ends