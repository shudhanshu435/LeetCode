// { Driver Code Starts
//
// Created by Tanuj Johal on 24-06-2020.
//
#include <bits/stdc++.h>
using namespace std;

long long countPairs(int *a,int n);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[n+1];
        for(int i=0;i<n;i++)
            cin>>a[i];
        long long ans = countPairs(a,n);
        cout<<ans<<endl;
    }
}

// } Driver Code Ends




long long countPairs(int a[],int n){
    // Complete the function and return the answer.
    sort(a,a+n);
    int cnt=0,cnt2=0;
    int i=0;
    if(n==1)return 0;
    while(a[i]==a[0]){
        cnt++;
        i++;
    }
    int j=n-1;
    while(a[n-1]==a[j]){
        cnt2++;
        j--;
    }
    
    return cnt*cnt2;
}