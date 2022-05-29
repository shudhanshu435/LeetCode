class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int count=0,cnt=0;
        for(int i=0;i<arr1.size();i++){
            cnt=0;
            for(int j=0;j<arr2.size()/2;j++){
                if(abs(arr1[i]-arr2[j])<=d || abs(arr1[i]-arr2[arr2.size()-1-j])<=d){
                    cnt++;
                    break;
                }
            }
            if(cnt==0){
                if(arr2.size()%2 != 0){
                int m = arr2.size()/2;
                if(abs(arr1[i]-arr2[m])<=d)cnt++;
                }
            }     
            if(cnt==0)count++;
        }
        return count;
    }
};