#include <bits/stdc++.h>
using namespace std;
int main()
{
    // code
    int t;
    cin >> t;
    while (t--)
    {
        int n, x, ans;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
            int cnt=0;
        for(int i=0;i<n;i++)if(arr[i]>x)cnt++;
        cout<<cnt<<endl;
    }
    return 0;
}