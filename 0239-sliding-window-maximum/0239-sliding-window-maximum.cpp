class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<pair<int,int>>dq;
        vector<int>vec;
        int i;
        for(i=0;i<k;i++){
            while(!dq.empty() and dq.back().first<nums[i]){
                dq.pop_back();
            }
            dq.push_back({nums[i],i});
        }
        vec.push_back(dq.front().first);
        int kk=0;
        for(;i<nums.size();i++){
            if(dq.front().second==kk){
                dq.pop_front();
            }
            while(!dq.empty() and dq.back().first<nums[i]){
                dq.pop_back();
            }
            dq.push_back({nums[i],i});
            vec.push_back(dq.front().first);
            kk++;
        }
        return vec;
    }
};