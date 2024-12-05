class Solution {
public:
    bool canChange(string start, string target) {
        int n=start.size();
        int i=0;
        string a="",b="";
        vector<int>ia,ib;
        for(;i<n;i++){
            if(start[i]!='_'){
                a+=start[i];
                ia.push_back(i);
            }
            if(target[i]!='_'){
                b+=target[i];
                ib.push_back(i);
            }
        }
        cout<<a<<b<<endl;
        if(a!=b)return 0;
        for(int i=0;i<a.length();i++){
            if(a[i]=='L' and ia[i]<ib[i])return 0;
            else if(a[i]=='R' and ia[i]>ib[i])return 0;
        }
        return 1;
    }
};

// L1,R4,R7

// L0,R7,R8