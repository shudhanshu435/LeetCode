class Solution {
public:
    int numberOfArrays(vector<int>& dif, int lower, int upper) {
        int n=dif.size();
        long long mini=1,maxi=1;
        vector<long long>v;
        v.push_back(1);
        for(int i=0;i<n;i++){
            v.push_back(v.back()+dif[i]);
            mini=min(mini,v.back());
            maxi=max(maxi,v.back());
        }
        // for(auto i:dif)cout<<i<<" ";
        // cout<<endl;
        // cout<<mini<<" "<<maxi<<endl;

        if(maxi-mini>upper-lower)return 0;
        return (upper-lower+1-maxi+mini);
    }
};

/*
   1  -3  4
x1, x2, x3, x4
1   2   -1 3
2   3    0 4
3   4    1 5
4   5    2 6
5   6    3 7
6   7    4 8
7   8    5 9


   3   -4  5    1  -2
x1   x2  x3  x4  x5  x6

1    4   0   5   6  4
2    5   1   6   7  5   
3    6   2   7   8  6


  4   7   -2
4   8   15  13

*/