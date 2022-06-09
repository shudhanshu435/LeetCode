class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int>vec;
        for(int i=0,j=numbers.size()-1;i<j;){
            if(numbers[i]+numbers[j]==target){
                vec.push_back(i+1);
                vec.push_back(j+1);
            }
            if(numbers[i]+numbers[j]<target)i++;
            else j--;
        }
        return vec;
    }
};