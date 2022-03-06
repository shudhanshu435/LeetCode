class Solution {
public:
    vector<int> sortEvenOdd(vector<int>& nums) {
        vector<int>ev;
        vector<int>od;
        vector<int>res;
        if(nums.size()==1){
            res.push_back(nums[0]);
            return res;
        }
        for(int i=0;i<nums.size();i++){
            if(i&1)od.push_back(nums[i]);
            else ev.push_back(nums[i]);
        }
        
        sort(ev.begin(),ev.end());
        sort(od.begin(),od.end());
        reverse(od.begin(),od.end());
        for(int i=0;i<nums.size()/2;i++){
            res.push_back(ev[i]);
            res.push_back(od[i]);
        }
        if(nums.size()&1)res.push_back(ev[ev.size()-1]);
        return res;
    }
};
