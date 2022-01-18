// { Driver Code Starts
//Initial Template for C++

#include <iostream>
using namespace std;


 // } Driver Code Ends
//User function Template for C++
#include<bits/stdc++.h>
void reverse_dig(int &a,int &b)
{
    //Add your code here.
    string ss="",sss="";
    ss+=to_string(a);
    sss+=to_string(b);
    reverse(ss.begin(),ss.end());
    reverse(sss.begin(),sss.end());
    a=stoi(ss);
    b=stoi(sss);
}
void swap(int &a,int &b)
{
    //Add your code here.
    a=a+b;
    b=a-b;
    a=a-b;
    
}


// { Driver Code Starts.

int main() 
{
    int t;
    cin>>t;
    while(t--)
    {
        int a, b;
	    cin>>a>>b;
	
	    reverse_dig(a,b);
	    swap(a,b);
	    cout<<a<<" "<<b<<endl;
    }
	return 0;
}  // } Driver Code Ends