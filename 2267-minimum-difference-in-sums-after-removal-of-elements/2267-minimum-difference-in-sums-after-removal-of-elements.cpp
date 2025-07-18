class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        int N=nums.size();
        int n=N/3;

        vector<long long>leftMinSum(N,0);
        vector<long long>rightMaxSum(N,0);

        priority_queue<int>maxHeap;
        long long curr=0;
        for(int i=0;i<n*2;i++){
            maxHeap.push(nums[i]);
            curr+=nums[i];

            if(maxHeap.size()>n){
                curr-=maxHeap.top();
                maxHeap.pop();
            }

            leftMinSum[i]=curr;
        }

        priority_queue<int, vector<int>, greater<int>> minHeap;
        curr=0;
        for(int i=N-1;i>=n;i--){
            minHeap.push(nums[i]);
            curr+=nums[i];

            if(minHeap.size()>n){
                curr-=minHeap.top();
                minHeap.pop();
            }

            rightMaxSum[i]=curr;
        }

        long long res=LLONG_MAX;
        for(int i=n-1;i<=2*n-1;i++){
            res=min(res,leftMinSum[i]-rightMaxSum[i+1]);
        }

        return res;
    }
};