using pp=pair<int,int>;

class Solution {
public:
    long long minimumCost(vector<int>& nums, int k, int dist) {
        int n=nums.size();
        multiset<int>sm,lg;
        int d=dist+1;
        
        int kk=1;
        long long ans=LLONG_MAX;
        long long cur=0;
        while(kk<n and d--){
            sm.insert(nums[kk]);
            cur+=nums[kk];
            if(sm.size()>k-1){
                int ele=*prev(sm.end());
                cur-=ele;
                lg.insert(ele);
                sm.erase(sm.find(ele));
            }
            kk++;
        }

        ans=min(ans,cur);

        for(int i=1;i+dist+1<n;i++){
            long long ele=nums[i+dist+1];
            sm.insert(ele);
            cur+=ele;
            if(sm.size()>k-1){
                int rem=*prev(sm.end());
                cur-=rem;
                lg.insert(rem);
                sm.erase(sm.find(rem));
            }

            if(sm.find(nums[i])!=sm.end()){
                sm.erase(sm.find(nums[i]));
                cur-=nums[i];
                if(!lg.empty()){
                    int tk=*lg.begin();
                    lg.erase(lg.find(tk));
                    cur+=tk;
                    sm.insert(tk);
                }
            }
            else{
                auto it=lg.find(nums[i]);
                if(it!=lg.end())lg.erase(it);
            }
            ans=min(ans,cur);
        }

        return ans+nums[0];

    }
};