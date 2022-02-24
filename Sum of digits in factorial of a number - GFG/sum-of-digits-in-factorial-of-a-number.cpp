// { Driver Code Starts
// C++ program to find sum of digits in factorial
// of a number
#include <bits/stdc++.h>
using namespace std;

// Function to multiply x with large number
// stored in vector v. Result is stored in v.
void multiply(vector<long long int> &v, long long int x);

// Returns sum of digits in n!
long long int findSumOfDigits(long long int n);

// Driver code
int main()
{
    long long int t;
    cin>>t;
    while(t--)
    {
        long long int n;
        cin>>n;
        cout << findSumOfDigits(n)<<endl;
    }
    return 0;
}
// } Driver Code Ends


/*Complete the function below*/
// Returns sum of digits in n!

int factorial(int x,int arr[],int len){
    int carry=0;
    for(int i=0;i<len;i++){
        int ss=arr[i]*x+carry;
        arr[i]=ss%10;
        carry=ss/10;
    }
    while(carry){
        arr[len]=carry%10;
        carry/=10;
        len++;
    }
    return len;
}

long long int findSumOfDigits(long long int n)
{

// Your code goes here
  int arr[100000];
  arr[0]=1;
  int len=1;
  for(int i=2;i<=n;i++){
      len=factorial(i,arr,len);
  }
  long long int sum=0;
  for(int i=0;i<len;i++){
      sum+=arr[i];
  }
  return sum;
  

}