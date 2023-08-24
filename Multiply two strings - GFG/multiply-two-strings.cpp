//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
 

// } Driver Code Ends
class Solution{
  public:
    /*You are required to complete below function */
    string multiplyStrings(string s1, string s2) {
       //Your code here
        int l1=s1.length();
        int l2=s2.length();
        
        int m=0,n=0;
        if(s1[0]=='-')m=1;
        if(s2[0]=='-')n=1;
        
        vector<int>vec(l1+l2,0);
        int pf=0;
        for(int i=l1-1;i>=m;i--){
            int carry=0;
            int k = vec.size()-1-pf;
            for(int j = l2-1;j>=n;j--){
                int prod = ((s1[i]-'0')*(s2[j]-'0'))+carry+vec[k];
                vec[k--] = prod % 10;
                carry = prod / 10;
            }
            vec[k]=carry;
            pf++;
        }
        // for(int i=0;i<vec.size();i++)cout<<vec[i]<<" ";
        int i=0;
        while(i<vec.size()&&vec[i]==0)i++;
        if(i==(l1+l2))return "0";
        string ans="";
        while(i<vec.size()){
            ans+=to_string(vec[i]);
            i++;
        }
        
        if((s1[0]=='-' && s2[0]!='-')||(s1[0]!='-' && s2[0]=='-')){
            string newans="-";
            newans+=ans;
            return newans;
        }
        return ans;
    }

};

//{ Driver Code Starts.
 
int main() {
     
    int t;
    cin>>t;
    while(t--)
    {
    	string a;
    	string b;
    	cin>>a>>b;
    	Solution obj;
    	cout<<obj.multiplyStrings(a,b)<<endl;
    }
     
}
// } Driver Code Ends