class Solution {
public:
    int minimumSum(int num) {
    vector<int>vec;
        
        while(num>0)
        {
            int temp=num%10;
            vec.push_back(temp);
            num/=10;
        }
        sort(vec.begin(),vec.end());
        return vec[0]*10+vec[3]+vec[1]*10+vec[2];
        
    }
};