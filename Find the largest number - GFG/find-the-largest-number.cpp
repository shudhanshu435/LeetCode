// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

 // } Driver Code Ends
class Solution{
public:
    
    int find(int N){
        // code here
        int m=N,cnt=0;
        while(1){
            m=N;
            cnt=0;
            while(m)
            {
            if((m%10)<((m/10)%10))cnt++;
            m/=10;
            }
            if(cnt==0){
                return N;
                break;
                
            }
            N--;
            
        }
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        Solution ob;
        cout << ob.find(N) << endl;
    }
    return 0; 
}  // } Driver Code Ends