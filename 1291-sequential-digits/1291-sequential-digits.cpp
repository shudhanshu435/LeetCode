class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<string>vec={"12","123","1234","12345","123456","1234567","12345678","123456789"};
        vector<int>num;
        for(auto &i:vec){
            num.push_back(stoi(i));
            int s=9-i.size();
            while(s--){
                for(int k=0;k<i.size();k++){
                    i[k]++;
                }
                num.push_back(stoi(i));
            }
        }
        vector<int>ans;
        for(auto i:num)if(i>=low and i<=high)ans.push_back(i);
        return ans;
    }
};