#include<iostream>
using namespace std;
int main()
 {
	//code
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    string s;
	    if(n<10){
	        string ss=to_string(n);
	        s+=ss;
	    }
	    else{
	        int m=n/9;
	        int g=n%9;
	        if(g!=0){
	        string ss=to_string(g);
	        s+=ss;}
	        while(m--)s+='9';
	    }
	    while(n--)s+='0';
	    cout<<s<<endl;
	}
	return 0;
}