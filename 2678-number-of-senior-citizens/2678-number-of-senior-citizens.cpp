class Solution {
public:
    int countSeniors(vector<string>& details) {
        int cnt=0;
        for(auto x:details){
            if(x[11]=='6'&&x[12]=='0')continue;
            else if(x[11]>='6')cnt++;
        }
        return cnt;
    }
};