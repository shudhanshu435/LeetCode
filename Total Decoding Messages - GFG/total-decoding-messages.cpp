//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
	int mod=1e9+7;
		int CountWays(string str){
		    // Code here
		    if(str[0]=='0')return 0;
		    int len=str.size();
		    vector<int>vec(len+1,0);
		    vec[0]=1;
		    vec[1]=1;
		    for(int i=2;i<=len;i++){
		        if(str[i-1]>'0')vec[i]=vec[i-1];
		        if(str[i-2]=='1'||(str[i-2]=='2' && str[i-1]<'7'))vec[i]=(vec[i]+vec[i-2])%mod;
		    }
		    return vec[len];
		    
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.CountWays(str);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends