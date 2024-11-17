class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n=nums.size();
        deque<int>deq;
        vector<long long>cumsum(n,0);

        int res = INT_MAX;
        int j=0;

        while(j<n){
            if(j==0)cumsum[j]=nums[j];
            else cumsum[j]=cumsum[j-1]+nums[j];

            if(cumsum[j]>=k)res=min(res,j+1);

            while(!deq.empty() and cumsum[j]-cumsum[deq.front()]>=k){
                res=min(res,j-deq.front());
                deq.pop_front();
            }
            while(!deq.empty() and cumsum[j]<=cumsum[deq.back()]){
                deq.pop_back();
            }
            deq.push_back(j++);
        }
        if(res==INT_MAX)return -1;
        return res;
    }
};