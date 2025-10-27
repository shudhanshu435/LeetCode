class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if(num*9<sum)return "";
        int div=sum/9;
        int rem=sum%9;
        string s="";
        for(int i=0;i<num;i++){
            if(i<div)s+="9";
            else if(i==div)s+=to_string(rem);
            else s+="0";
        }
        return s;

    }
};