//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int maxInstance(string s){
        int b=0,a=0,l=0,o=0,n=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='b')b++;
            else if(s[i]=='a')a++;
            else if(s[i]=='l')l++;
            else if(s[i]=='o')o++;
            else if(s[i]=='n')n++;
        }
        int x=min(l,o);
        int m=min(b,min(a,n));
        if(x==0 || m==0)return 0;
        if(x&1)n--;
        return min(x/2,m);
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.maxInstance(s)<<endl;
    }
    return 0;
}
// } Driver Code Ends