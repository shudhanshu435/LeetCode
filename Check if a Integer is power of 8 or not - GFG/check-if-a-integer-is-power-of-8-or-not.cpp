// { Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution {
public:
    string is_power_of_eight(long long int n ) 
    {
        // Code here.
        for(int i=0;i<=25;i++){
            if(pow(8,i)==n)return "Yes";
            if(pow(8,i)>n)return "No";
        }return "No";
    }
};


// { Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	long long int  n;
    	cin >> n;
    	Solution ob;
    	string ans = ob.is_power_of_eight(n);
    	cout << ans << "\n";
    }
	return 0;
}
  // } Driver Code Ends