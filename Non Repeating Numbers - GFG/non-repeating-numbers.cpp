// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
public:
    vector<int> singleNumber(vector<int> nums) 
    {
        // Code here.
        vector<int>vec;
        sort(nums.begin(),nums.end());
        if(nums.size()==1)vec.push_back(nums[0]);
        if(nums[0]!=nums[1])vec.push_back(nums[0]);
        
        for(int i=1;i<nums.size()-1;i++){
            if((nums[i]!=nums[i-1])&&(nums[i]!=nums[i+1]))vec.push_back(nums[i]);
        }
        if(nums[nums.size()-1]!=nums[nums.size()-2])vec.push_back(nums[nums.size()-1]);
        return vec;
    }
};

// { Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	vector<int> v(2 * n + 2);
    	for(int i = 0; i < 2 * n + 2; i++)
    		cin >> v[i];
    	Solution ob;
    	vector<int > ans = ob.singleNumber(v);
    	for(auto i: ans)
    		cout << i << " ";
    	cout << "\n";
    }
	return 0;
}  // } Driver Code Ends