class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        long long cnt=0;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        // for(auto i:nums)cout<<i<<' ';
        // cout<<endl;
        for(int i=0;i<n-1;i++){
            int l=lower-nums[i];
            auto it=lower_bound(nums.begin(),nums.end(),l);
            int ind=it-nums.begin();
            if(ind<=i)l=i+1;
            else l=ind;
            // if(l<=nums[i])l=nums[i+1];
            // if(ind==n)continue;
            
            int u=upper-nums[i];
            auto ut=upper_bound(nums.begin(),nums.end(),u);
            int indd=ut-nums.begin();
            // if(indd<ind)break;
            if(indd-l<0)break;

            // cout<<ind<<" "indd<<endl;
            // cout<<indd-l<<endl;
            cnt+=(indd-l);
            

        }
        return cnt;
    }
};

// 0 1 4 4 5 7