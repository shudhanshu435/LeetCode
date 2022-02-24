// { Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

vector<int> fact(int n);


int main(){
    int t;
    cin>>t;
    
    while(t--){
        int n;
        cin>>n;
        vector<int> v;
        v = fact(n);
        
        for(int i: v){
            cout << i << " ";
        }
        cout << endl;

    }
    
}  // } Driver Code Ends

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

vector<int> fact(int n){
   
  // Complete the function
  int arr[100000];
  arr[0]=1;
  int len=1;
  for(int i=2;i<=n;i++){
      len=factorial(i,arr,len);
  }
  long long int sum=0;
  vector<int>vec;
  vec.push_back(arr[len-1]);
  vec.push_back(len-1);
  return vec;
}
 
 
 