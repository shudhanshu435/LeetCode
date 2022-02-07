// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
public:
int minimum_difference(vector<int> nums)
{
    // Code here
    sort(nums.begin(),nums.end());
    int min = abs(nums[0] - nums[1]);
    for (int i = 2; i < nums.size(); i++)
    {
        if (abs(nums[i - 1] - nums[i]) < min)min=abs(nums[i-1]-nums[i]);
    }
    return min;
}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < nums.size(); i++)cin >> nums[i];
		Solution ob;
		int ans = ob.minimum_difference(nums);
		cout << ans <<"\n";
	}  
	return 0;
}  // } Driver Code Ends