// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    unsigned int reverseBits(unsigned int n)
    {
        //code here
        long long int arr[100];
        int i=0,cnt=0;
        while(n){
            arr[i]=n&1;
            n>>=1;
            i++;
            cnt++;
        }
        unsigned int sum=0;
        for(int i=0;i<cnt;i++){
            if(arr[i]==1)
            sum+=pow(2,cnt-1-i);
        }return sum;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        
        Solution ob;
        cout<< ob.reverseBits(N) <<"\n";
        
    }
    return 0;
}
  // } Driver Code Ends