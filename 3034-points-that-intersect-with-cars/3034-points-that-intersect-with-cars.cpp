class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) {
        vector<int>vec(102,0);
        for(auto i:nums){
            vec[i[0]]+=1;
            vec[i[1]+1]-=1;
        }
        int cnt=0;
        for(int i=1;i<102;i++){
            vec[i]=vec[i]+vec[i-1];
            if(vec[i]!=0)cnt++;
        }
        return cnt;

    }
};