// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends

class Solution
{
public:
    vector<long long> printSeries(int N)
    {
        // Write your code here
        vector<long long>vec;
        if (N == 1)
            vec.push_back(1);
        else if (N == 2)
        {
            vec.push_back(1);
            vec.push_back(2);
        }
        else
        {
            vec.push_back(1);
            vec.push_back(2);
            vec.push_back(5);
            if (N > 3)
            {
                long long int temp;
                long long int a = 1, b = 2, c = 5;
                for(int i=4;i<=N;i++)
                {
                
                    temp = a + b + c;
                    vec.push_back(temp);
                    a = b;
                    b = c;
                    c = temp;
                
                }
            
            }
        }
        return vec;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        
        Solution ob;
        vector<long long> a = ob.printSeries(N);
        
        for(long long i=0;i<N;i++){
            cout<<a[i]<<" ";
        }
        cout<<endl;
        
    }
    return 0;
}  // } Driver Code Ends