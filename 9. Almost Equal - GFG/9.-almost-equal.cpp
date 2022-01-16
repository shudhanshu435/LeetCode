// { Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;



 // } Driver Code Ends
//User function Template for C++

/*Function to count number of characters 
* to make s1 and s2 equal
* s1 : first string
* s2 : second string
*/
class Solution{
    public:
    int countChars(string s1, string s2){
        
        // Your code here
        int a[257]={0};
        int b[257]={0};
        int res=0;
        for(int i=0;i<s1.length();i++)a[s1[i]]++;
        for(int i=0;i<s2.length();i++)b[s2[i]]++;
        for(int i=0;i<257;i++)res+=abs(b[i]-a[i]);
        
        return res;
        
    }
};

// { Driver Code Starts.
int main() {
	
	int testcase;
	
	cin >> testcase;
	
	while(testcase--){
	    
	    // taking string input
	    string s1, s2;
	    cin >> s1 >> s2;
	    Solution obj;
	    cout << obj.countChars(s1, s2) << endl;
	}
	
	return 0;
}  // } Driver Code Ends