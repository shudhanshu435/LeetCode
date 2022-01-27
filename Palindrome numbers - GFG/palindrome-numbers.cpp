// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

 // } Driver Code Ends
class Solution{
public:
    int isPallindrome(long long int N){
        // code here
        string s="";
        while(N){
            s+=N&1;
            N>>=1;
        }
        string ss=s;
        reverse(s.begin(),s.end());
        for(int i=0;i<s.length();i++){
            if(s[i]!=ss[i])return 0;
        }return 1;
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        long long int N;
        cin>>N;
        Solution ob;
        cout << ob.isPallindrome(N) << endl;
    }
    return 0; 
}  // } Driver Code Ends