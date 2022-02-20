// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution{
    public:
    int bubbleSort(int arr[], int num)
    {
    int cnt = 0,count=0;
    for (int i = 1; i <= num; i++)
    {
        for (int j = 1; j <= num - i; j++)
        {
            if (arr[j - 1] > arr[j])
            {
                cnt++;
                int temp;
                count++;
                temp = arr[j - 1];
                arr[j - 1] = arr[j];
                arr[j] = temp;
            }
        }
        
    }
    return count;
    }
    int shouldPunish (int roll[], int marks[], int n, double avg)
    {
        // your code here
        double sum=0;
        int t=bubbleSort(roll,n);
        for(int i=0;i<n;i++){
            sum+=marks[i];
        }
        double avgg=(sum-t*2)/n;
        if(avgg>=avg)return 1;
        else return 0;
    }
};

// { Driver Code Starts.
int main()
{
	int t; cin >> t;
	while (t--)
	{
		int n; cin >> n;
		double avg; cin >> avg;

		int roll[n];
		int marks[n];

		for (int i = 0; i < n; ++i)
			cin >> roll[i];
		for (int i = 0; i < n; ++i)
			cin >> marks[i];
        Solution ob;
		cout << ob.shouldPunish (roll, marks, n, avg) << endl;
	}
}
  // } Driver Code Ends