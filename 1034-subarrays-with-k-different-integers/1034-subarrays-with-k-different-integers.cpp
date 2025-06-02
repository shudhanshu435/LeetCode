class Solution {
public:
    int func(vector<int>&s, int k){
        unordered_map<int,int>mp;
        int x=0;
        int cnt=0;
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
            while(mp.size()>k){
                mp[s[x]]--;
                if(mp[s[x]]==0)mp.erase(s[x]);
                x++;
            }
            cnt+=i-x+1;
        }
        return cnt;
        
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return func(nums,k)-func(nums,k-1);
    }
};