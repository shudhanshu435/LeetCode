// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



 // } Driver Code Ends

class Solution{
  public:
    long long int printMinimumProduct(int arr[], int n) {
        sort(arr,arr+n);
        return (long long int)arr[0]*arr[1];
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int i, a[n];
        for (i = 0; i < n; i++) cin >> a[i];
        Solution obj;
        cout << obj.printMinimumProduct(a, n) << endl;
    }
    return 0;
}
  // } Driver Code Ends