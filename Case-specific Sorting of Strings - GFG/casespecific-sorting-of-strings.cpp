// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution
{
    public:
    //Function to perform case-specific sorting of strings.
    string caseSort(string str, int n)
    {
        // your code here
        string result="";
        string res=str;
        sort(str.begin(),str.end());
        for(int i=0;i<n;i++){
            if(res[i]>='a'&&res[i]<='z'){
                for(int i=0;i<n;i++){
                    if(str[i]>='a'&&str[i]<='z'){
                    result+=str[i];
                    str.erase(i,1);
                    break;}
                }
            }
            else
            {
                for(int i=0;i<n;i++){
                    if(str[i]>='A'&&str[i]<='Z'){
                    result+=str[i];
                    str.erase(i,1);
                    break;}
                }
            }
        }
        return result;
    }
};

// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		string str;
		cin>>str;
		Solution obj;
		cout<<obj.caseSort (str, n)<<endl;
	}
}  // } Driver Code Ends