//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
  public:	
	int distinctSubsequences(string s)
	{
        int mod=1e9+7;
	    // Your code goes here
	    int len=s.size();
	    vector<int>vec(len+1);
	    vec[0]=1;
	    unordered_map<char,int>mp;
	    for(int i=0;i<len;i++){
	        vec[i+1]=(vec[i]*2)%mod;
	        char ch=s[i];
	        if(mp[ch]){
            //to find index of character from last
                int index=mp[ch];
                vec[i+1]=((vec[i+1]-vec[index-1]+mod)%mod);
	        }
	        mp[ch]=i+1;
	    }
	    return vec[len];
	}
};

//{ Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string s;
   		cin >> s;

        Solution ob;
   		cout << ob.distinctSubsequences(s) << "\n";
   	}

    return 0;
}
// } Driver Code Ends