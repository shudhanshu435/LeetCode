class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        vector<int>res;
        res=arr;
        sort(arr.begin(),arr.end());
        int m=arr[arr.size()-1];
        int t;
        for(int i=0;i<arr.size();i++){
            if(res[i]==m){
                t=i;break;
            }
        }
        return t;
    }
};