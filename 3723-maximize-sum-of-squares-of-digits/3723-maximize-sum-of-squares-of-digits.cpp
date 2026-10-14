class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if(sum>9*num)return "";
        string ans="";
        int x=sum/9;
        num-=x;
        while(x--){
            ans+='9';
        }
        int r=sum%9;
        if(num>0)ans+=(r+'0');
        while(num-->1)ans+='0';

        return ans;
    }
};

// _ _ _ _ _ _ _ 9 - 8

// 50

