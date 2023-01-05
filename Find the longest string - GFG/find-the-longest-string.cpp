//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
 
class Solution
{
public:
    string longestString(vector<string> &words)
    {
        // code here
        unordered_map<string,int>mp;
        sort(words.begin(),words.end());
        string ans="";
        int size=0;
        for(auto i:words)mp[i]++;
        for(auto x: words){
            string temp="";
            int siz=x.length(),cnt=0;
            for(int i=0;i<siz;i++){
                temp+=x[i];
                if(mp[temp])cnt++;
                else break;
            }
            if(cnt==siz && siz>size){
                ans=temp;
                size=siz;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<string> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        Solution obj;
        string w = obj.longestString(v);
        cout << w << "\n";
    }
    return 0;
}

// } Driver Code Ends