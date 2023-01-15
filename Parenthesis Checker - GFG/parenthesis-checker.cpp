//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
        // Your code here
        stack<char>st;
        for(char i: x){
            if(i=='('||i=='{'||i=='[')st.push(i);
            else{
                if(!st.empty()&&i==')'&&st.top()=='(')st.pop();
                else if(!st.empty()&&i=='}'&&st.top()=='{')st.pop();
                else if(!st.empty()&&i==']'&&st.top()=='[')st.pop();
                else st.push(i);
                
            }
        }
        if(st.empty())return true;
        else return false;
    }

};

//{ Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}
// } Driver Code Ends