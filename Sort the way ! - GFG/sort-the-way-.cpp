// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution{
    public:
    int isPossible (int per[], int vac[], int n)
    {
        // your code here
        sort(per,per+n);
        sort(vac,vac+n);
        int i=0,cnt=0;
        while(i<n){
            if(vac[i]<per[i]){
                cnt++;
                break;
            }
            i++;
        }if(cnt!=0)return 0;
        else return 1;
    }
};

// { Driver Code Starts.
int main()
{
	int t; cin >> t;
	while (t--)
	{
		int n; cin >> n;
		int per[n];
		int vac[n];

		for (int i = 0; i < n; ++i)
			cin >> vac[i];

		for (int i = 0; i < n; ++i)
			cin >> per[i];
        Solution ob;
		cout << ob.isPossible (per, vac, n) << endl;
	}
}

// Contributed By: Pranay Bansal  // } Driver Code Ends