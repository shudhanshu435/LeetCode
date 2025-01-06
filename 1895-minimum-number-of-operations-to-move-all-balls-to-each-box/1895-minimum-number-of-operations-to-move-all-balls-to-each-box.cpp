class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int>one;
        for(int i=0;i<boxes.size();i++){
            if(boxes[i]=='1')one.push_back(i);
        }
        vector<int>vec;
        for(int j=0;j<boxes.size();j++){
            int sum=0;
            for(auto i:one){
                sum+=abs(j-i);
            }
            vec.push_back(sum);
        }
        return vec;
    }
};