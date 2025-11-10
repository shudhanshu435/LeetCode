class Solution {
public:
    int minOperations(vector<int>& nums) {
        stack<int>s;
        int n=nums.size();
        unordered_map<int,bool>mp;
        int cnt=0;
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                s.push(0);continue;
            }
            if(!mp[nums[i]]){
                cnt++;
                s.push(nums[i]);
                mp[nums[i]]=1;
            }
            else{
                while(!s.empty()){
                    if(s.top()>nums[i])s.pop();
                    else break;
                }
                if(s.top()<nums[i])cnt++;
                s.push(nums[i]);
            }
        }
        return cnt;
    }
}; 