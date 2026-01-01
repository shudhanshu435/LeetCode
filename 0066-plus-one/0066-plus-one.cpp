class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry=1;
        int n=digits.size();
        for(int i=n-1;i>=0;i--){
            int curr=digits[i]+carry;
            digits[i]=curr%10;
            carry=curr/10;
        }
        if(carry){
            digits.insert(digits.begin(),1);
        }
        return digits;
    }
};