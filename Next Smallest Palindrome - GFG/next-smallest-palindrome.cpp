//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:
    void generatePalindrome(int num[], int n){
        int mid=n/2;
        bool leftSmaller = false;
        int i = mid-1;
        int j = (n%2)?mid+1:mid;
        while(i>=0 && num[i]==num[j])i--,j++;
        if(i<0 || num[i]<num[j])leftSmaller=1;
        while(i>=0){
            num[j]=num[i];
            j++;
            i--;
        }
        if(leftSmaller==true){
            int carry=1;
            i=mid-1;
            if(n&1){
                num[mid]+=carry;
                carry=num[mid]/10;
                num[mid]%=10;
                j=mid+1;
            }
            else j=mid;
            while(i>=0){
                num[i]+=carry;
                carry=num[i]/10;
                num[i]%=10;
                num[j++]=num[i--];
            }
        }
    }
	vector<int> generateNextPalindrome(int num[], int n) {
	    // code here
	    vector<int>vec;
	    int cnt=0;
	    for(int i=0;i<n;i++)if(num[i]==9)cnt++;
	    if(cnt==n){
	        vec.push_back(1);
	        for(int i=1;i<n;i++)vec.push_back(0);
	        vec.push_back(1);
	        return vec;
	    }
	    generatePalindrome(num,n);
	    for(int i=0;i<n;i++)vec.push_back(num[i]);
        return vec;
	}

};

//{ Driver Code Starts.


int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int num[n];
        for (int i = 0; i < n; i++) {
            cin >> num[i];
        }
        Solution ob;
        auto ans = ob.generateNextPalindrome(num, n);
        for (auto x : ans) {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends