// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
        vector <int> search(string pat, string txt)
        {
            //code here.
            int cnt=0;
            vector<int>vec;
            int len=pat.length();
            for (int i = 0; i < txt.length(); i++)
            {
               if (txt.substr(i,len) == pat)
               {
                  vec.push_back(i+1);
                  cnt++;
               }
            }
          if(cnt!=0)return vec;
          else{
              vec.push_back(-1);
              return vec;
          } 
        }
     
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S, pat;
        cin >> S >> pat;
        Solution ob;
        vector <int> res = ob.search(pat, S);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}

// Contributed By: Pranay Bansal
  // } Driver Code Ends