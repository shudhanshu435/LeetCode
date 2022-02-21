// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

bool isFit(int a[], int b[], int n);

int main()
{
    int i,j,z,t,n,flag;
    cin>>t;
    for(z=0;z<t;z++)
    {
        flag=0;
        cin>>n;
        int a[n+1], b[n+1];
        
        for(i=0;i<n;i++)
            cin>>a[i];
        for(i=0;i<n;i++)
            cin>>b[i];
        
        if(isFit(a, b, n))  cout<<"YES\n";
        else
            cout << "NO\n";
            
        
    }
    return 0;
}// } Driver Code Ends



bool isFit(int a[], int b[], int n){
    // Complete the function
    sort(a,a+n);
    sort(b,b+n);
    for(int i=0;i<n;i++){
        if(a[i]>b[i])return false;
    }return true;
}
