class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int size=arr.size();
        if(size<3)return false;
        for(int i=0;i<=size-3;i++){
            if((arr[i]&1)&&(arr[i+1]&1)&&(arr[i+2]&1))return true;
        }return false;
    }
};