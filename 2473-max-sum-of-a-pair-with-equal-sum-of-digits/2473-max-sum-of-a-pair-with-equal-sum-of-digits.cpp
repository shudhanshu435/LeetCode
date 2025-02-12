template <typename T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;

class Solution {
public: 
    int sum(int n){
        int sum=0;
        while(n){
            sum+=n%10;
            n/=10;
        }
        return sum;
    }
    int maximumSum(vector<int>& nums) {
        unordered_map<int,int>mp;
        int ans=-1;
        for(auto i:nums){
            int s=sum(i);
            if(mp[s]!=0){
                int maxi=max(i,mp[s]);
                ans=max(ans,i+mp[s]);
                mp[s]=maxi;
            }
            else
                mp[s]=i;
        }
        return ans;
    }
};