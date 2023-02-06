//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:

	void rearrange(int arr[], int n) {
	    // code here
	    int p=0,q=0;
	    vector<int>pos,neg;
	    for(int i=0;i<n;i++){
	        if(arr[i]>=0){pos.push_back(arr[i]);p++;}
	        else {neg.push_back(arr[i]);q++;}
	    }
	    int j=0,k=0;
	    for(int i=0;i<n;){
	        if(p>0){
	            arr[i++]=pos[j++];
	            p--;
	        }
	        if(q>0){
	            arr[i++]=neg[k++];
	            q--;
	        }
	    }
	    
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        ob.rearrange(arr, n);
        for (i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends