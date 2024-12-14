class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        map<int,int>mp;
        int n=nums.size();
        long long count=0;
        int i=0,j=0;
        for(int j=0;j<n;j++){
            mp[nums[j]]++;
            int mini=mp.begin()->first;
            int maxi=mp.rbegin()->first;
            while(abs(mini-maxi)>2){
                mp[nums[i]]--;
                if(mp[nums[i]]==0)mp.erase(nums[i]);
                i++;
                mini=mp.begin()->first;
                maxi=mp.rbegin()->first;
            }
            count+=(j-i+1);
        }
        return count;
    }
};


// 4 2 4 2 4 2 4