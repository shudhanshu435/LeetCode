//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
bool valid(string str);
int main()
{
    int t;
    cin>>t;
    cin.ignore();
    while(t--)
    {
        string str;
        getline(cin,str);
        cout<<valid(str)<<endl;
    }
    return 0;
}
// } Driver Code Ends


bool valid(string s)
{
    // code here
    if(s.length()&1)return 0;
    stack<int>st;
    for(auto x:s){
        if(x=='('||x=='{'||x=='[')st.push(x);
        else {
            if(x==')'){
                if(!st.empty()&&st.top()=='(')st.pop();
                else st.push(x);
            }
            else if(x=='}'){
                if(!st.empty()&&st.top()=='{')st.pop();
                else st.push(x);
            }
            else if(x==']'){
                if(!st.empty()&&st.top()=='[')st.pop();
                else st.push(x);
            }
        }
    }
    if(st.empty())return 1;
    else return 0;
}