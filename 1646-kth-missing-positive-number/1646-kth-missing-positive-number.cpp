class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        vector<int>miss;
        for(int i=0;i<arr.size();i++){
            miss.push_back(arr[i]-(i+1));
        }
        int ans=-1;
        for(int i=miss.size()-1;i>=0;i--){
            if(miss[i]<k){
                ans=(k-miss[i])+arr[i];
                break;
            }
        }
        if(ans==-1)ans=k;
        return ans;
        
    }
};