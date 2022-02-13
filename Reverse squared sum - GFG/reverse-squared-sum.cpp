#include<iostream>
using namespace std;
int main()
 {
	//code
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int arr[n];
	    int res=0;
	    for(int i=0;i<n;i++)cin>>arr[i];
	    for(int i=n-1;i>=0;i-=2){
	        res+=arr[i]*arr[i];
	        res-=arr[i-1]*arr[i-1];
	    }
	    cout<<res<<endl;
	}
	return 0;
}