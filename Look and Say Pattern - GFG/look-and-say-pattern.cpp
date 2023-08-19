//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    string lookandsay(int n) {
        // code here
        if(n==1)return "1";
        string s="1";
        int i=1;
        while(i++<n){
            s+='@';
            int cnt=1;
            string newstr="";
            int j=1;
            while(j<s.length()){
                if(s[j]==s[j-1])cnt++;
                else{
                    newstr+=char(cnt)+'0';
                    newstr+=s[j-1];
                    cnt=1;
                }
                j++;
            }
            s=newstr;
        }
        return s;
    }   
};

//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        Solution obj;
        cout<<obj.lookandsay(n)<<endl;
    }
    return 0;
}
// } Driver Code Ends