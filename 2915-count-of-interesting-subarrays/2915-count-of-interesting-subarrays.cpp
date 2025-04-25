class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int mod, int k) {
        for(auto &i:nums){
            if(i%mod==k)i=1;
            else i=0;
        }

        unordered_map<int,long long>mp;
        long long sum=0;
        long long res=0;
        mp[0]=1;
        
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            int r1=sum%mod;
            int r2=(r1-k+mod)%mod;
            res+=mp[r2];
            mp[r1]++;
        }
        return res;

    }
};

/*  
    3 2 4
    1 0 0
--------------
    1 1 1


    0,3,6,9,12,15,18,21,24,27,30............
    3 1 9 6 3 3 3
    1 0 1 1 1 1 1
---------------------
    1 1 2 3 4 5 6

6 - 6,3
5 - 3
4 - 3,3
3 - 3
2 - 
1 - 
0 - 0
*/