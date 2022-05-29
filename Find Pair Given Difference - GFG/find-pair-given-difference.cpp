// { Driver Code Starts
#include<bits/stdc++.h>
 
using namespace std; 


bool findPair(int arr[], int size, int n);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int l,n;
        cin>>l>>n;
        int arr[l];
        for(int i=0;i<l;i++)
            cin>>arr[i];
        if(findPair(arr, l, n))
            cout<<1<<endl;
        else cout<<"-1"<<endl;
    }
    
  
    return 0;
}// } Driver Code Ends


bool findPair(int arr[], int size, int n){
    //code
    
    vector<int>vec,tec;
    int snd=0;
    for(int i=0;i<size;i++){
        vec.push_back(arr[i]);
    }
    sort(vec.begin(),vec.end());
    for(int i=0;i<size;i++){
        if((vec[i]==vec[i+1])&&(i!=size-1))snd++;
    }
    if(n==0 && snd>0)return 1;
    else if(n==0 && snd==0)return 0;
    int cnt=0;
    tec=vec;
    for(int i=0;i<size;i++){
        //vec.erase(vec.begin()+i);
        if(find(vec.begin(),vec.end(),n+vec[i])!=vec.end()){
            cnt=1;
            break;
        }
        vec=tec;
    }
    if(cnt==1)return 1;
    else return 0;
    
}
