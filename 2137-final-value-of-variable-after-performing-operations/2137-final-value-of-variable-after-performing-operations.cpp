class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int x=0;
        for(auto &i:operations){
            if(i[0]=='-' or i[2]=='-')x--;
            else x++;
        }
        return x;
    }
};