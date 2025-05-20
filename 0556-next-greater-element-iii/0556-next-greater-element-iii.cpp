class Solution {
public:
    int nextGreaterElement(int n) {
        vector<int>v;
        int t=n;
        while(n){
            v.push_back(n%10);
            n/=10;
        }
        reverse(v.begin(),v.end());
        
        vector<int>temp=v;
        next_permutation(v.begin(),v.end());
        if(v<temp)return -1;

        long long num=0;
        for(auto i:v){
            num=(num*10)+i;
        }
        if(num < -2147483648 or num > 2147483647 or num==t)return -1;
        return num;

    }
};


// 1 2 4 2