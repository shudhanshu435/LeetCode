//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


vector<int> Smallestonleft(int arr[], int n);


int main() {
	
	int t;
	
	cin >> t;
	
	while(t--){
	    
	    int n;
	    cin >> n;
	    int arr[n+1];
	    
	    for(int i=0;i<n;i++){
	        cin>> arr[i];
	    }
	    
	    vector<int> b;
	    b = Smallestonleft(arr, n);
	    for(int i=0;i<n;i++)
	        cout << b[i] << " ";
	       
	    cout << endl;
	    
	    
	}
	
	return 0;
}
// } Driver Code Ends


vector<int> Smallestonleft(int arr[], int n)
{
    // Complete the function

    vector<int>vec;
    set<int>s;
    for(int i=0;i<n;i++){
        auto ind = s.lower_bound(arr[i]);
        if(ind == s.begin())vec.push_back(-1);
        else{
            ind--;
            vec.push_back(*ind);
        }
        s.insert(arr[i]);
    }
    return vec;
}