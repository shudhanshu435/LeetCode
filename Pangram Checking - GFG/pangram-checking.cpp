// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    //Function to check if a string is Pangram or not.
    bool checkPangram (string &str) {
        // your code here
        int cnt=0;
        char cc='a';
        for(int i=0;i<str.length();i++){
            str[i]=tolower(str[i]);
        }
        while(cc<='z'){
          for(int j=0;j<str.length();j++){
            if(str[j]==cc){
                cnt++;
                
                break;
            }
          }cc++;
        }if(cnt==26)return 1;
        else return 0;
    }

};

// { Driver Code Starts.

// Driver Program to test above functions
int main()
{
    int t;
    cin>>t;
    cin.ignore(INT_MAX, '\n');
    while(t--){
        string str;
        getline(cin, str);
        Solution obj;
        if (obj.checkPangram(str) == true)
            cout<<1<<endl;
        else
            cout<<0<<endl;
    }
    return(0);
}
  // } Driver Code Ends