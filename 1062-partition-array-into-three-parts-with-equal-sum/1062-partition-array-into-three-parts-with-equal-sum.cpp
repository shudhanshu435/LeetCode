class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) {
        int sum=accumulate(arr.begin(),arr.end(),0);
        if(sum%3!=0)return 0;
        sum/=3;
        int curr=0,cnt=0;
        for(int i=0;i<arr.size();i++){
            curr+=arr[i];
            if(curr==sum){
                cnt++;
                if(cnt==3)break;
                curr=0;
            }
        }
        if(cnt==3)return 1;
        return 0;
    }
};