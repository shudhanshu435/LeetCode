// { Driver Code Starts
//Initial template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
    long long maxProduct(int arr[], int n) {
        // code here
        sort(arr,arr+n);
        // unsigned long long res=(>=(arr[n-1]*arr[n-2]*arr[n-3]))?(arr[0]*arr[1]*arr[n-1]):(arr[n-1]*arr[n-2]*arr[n-3]);
            
        return max((1ll*arr[0]*arr[1]*arr[n-1]),(1ll*arr[n-1]*arr[n-2]*arr[n-3]));
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.maxProduct(arr, n);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends