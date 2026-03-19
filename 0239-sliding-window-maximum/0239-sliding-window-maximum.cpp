class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int>dq;
        int n=nums.size();
        for(int i=0;i<k;i++){
            while(!dq.empty() and dq.back()<nums[i]){
                dq.pop_back();
            }
            dq.push_back(nums[i]);
        }
        vector<int>ans;
        ans.push_back(dq.front());
        int m=0;
        if(dq.front()==nums[m++])dq.pop_front();
        for(int i=k;i<n;i++){
            while(!dq.empty() and dq.back()<nums[i]){
                dq.pop_back();
            }
            dq.push_back(nums[i]);
            ans.push_back(dq.front());
            if(dq.front()==nums[m++])dq.pop_front();
        }
        return ans;
    }
};