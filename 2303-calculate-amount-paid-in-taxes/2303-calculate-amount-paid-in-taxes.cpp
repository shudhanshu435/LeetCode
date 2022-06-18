class Solution {
public:
    double calculateTax(vector<vector<int>>& brackets, int income) {
        double sum=0;
        reverse(brackets.begin(),brackets.end());
        brackets.push_back({0,0});
        reverse(brackets.begin(),brackets.end());
        for(int i=1;i<brackets.size();i++){
            if(brackets[i][0]<income){
                sum+=(brackets[i][0]-brackets[i-1][0])*(brackets[i][1] / 100.00);
            }
            else{
                sum+=(income-brackets[i-1][0])*(brackets[i][1] / 100.00);
                break;
            }
        }
        return sum;
    }
};