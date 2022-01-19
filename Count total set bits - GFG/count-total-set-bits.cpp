// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    // n: input to count the number of set bits
    //Function to return sum of count of set bits in the integers from 1 to n.
    int findMaxPower(int n){
        int i=0;
        while(pow(2,i)<=n)
            i++;
            return i-1;
        
    }
    int countSetBits(int n)
    {
        // Your logic here
        if(n<=1)return n;
        int x=findMaxPower(n);
        return (x*pow(2,x-1))+(1+n-pow(2,x))+countSetBits(n-pow(2,x));
    }
    
    
};


// { Driver Code Starts.

// Driver code
int main()
{
	 int t;
	 cin>>t;// input testcases
	 while(t--) //while testcases exist
	 {
	       int n;
	       cin>>n; //input n
	       Solution ob;
	       cout << ob.countSetBits(n) << endl;// print the answer
	  }
	  return 0;
}
  // } Driver Code Ends