class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n=arr.size();
        int cnt=0;
        int maxi=-1;
        for(int i=0;i<n;i++){
            maxi=max(maxi,arr[i]);
            if(i==maxi)cnt++;
        }
        return cnt;
    }
};