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
        map<int,min_heap<int>>mp;
        int ans=-1;
        for(auto i:nums){
            int s=sum(i);
            mp[s].push(i);
            if(mp[s].size()==2){
                int t=mp[s].top();
                mp[s].pop();
                ans=max(ans,t+mp[s].top());
            }
        }
        return ans;
    }
};