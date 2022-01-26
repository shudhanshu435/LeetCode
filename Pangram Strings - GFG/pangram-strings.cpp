// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution
{
public:
    int isPanagram(string S)
    {
        // Your code goes here
        char c = 'a';
        for (int i = 0; i < S.length(); i++)
        {
            S[i] = tolower(S[i]);
        }
        int cnt = 0;
        while (c <= 'z')
        {
            for (int i = 0; i < S.length(); i++)
            {
                if (S[i] == c)
                {
                    cnt++;
                    break;
                }
            }
            c++;
        }
        if (cnt == 26)
            return 1;
        else
            return 0;
    }
};

// { Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	string tc;
   	getline(cin, tc);
   	t = stoi(tc);
   	while(t--)
   	{
   		string s;
   		getline(cin, s);

   	    Solution ob;

   		cout << ob.isPanagram(s) << "\n";
   	}

    return 0;
}  // } Driver Code Ends
