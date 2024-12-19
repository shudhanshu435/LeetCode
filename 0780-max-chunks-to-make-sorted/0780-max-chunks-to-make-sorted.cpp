class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        priority_queue<int>pq;
        int n=arr.size();
        int cnt=0;
        for(int i=0;i<n;i++){
            pq.push(arr[i]);
            if(i==pq.top())cnt++;
        }
        return cnt;
    }
};