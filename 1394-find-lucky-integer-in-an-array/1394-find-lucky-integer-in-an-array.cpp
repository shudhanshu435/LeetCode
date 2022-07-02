class Solution {
public:
    int findLucky(vector<int>& arr) {
        int hpp[501]={0};
        for(int i=0;i<arr.size();i++){
            hpp[arr[i]]++;
        }
        for(int i=500;i>0;i--){
            if(hpp[i]==i)return i;
        }
        return -1;
    }
};