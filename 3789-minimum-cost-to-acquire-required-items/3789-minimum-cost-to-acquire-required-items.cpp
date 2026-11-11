class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long ans=0;
        if(cost1+cost2<=costBoth){
            ans+=(cost1+cost2)*1ll*min(need1,need2);
            if(need2>need1)ans+=cost2*1ll*(need2-need1);
            else ans+=cost1*1ll*(need1-need2);
        }
        else{
            ans+=costBoth*1ll*min(need1,need2);
            if(need2>need1){
                ans+=min(cost2,costBoth)*1ll*(need2-need1);
            }
            else ans+=min(cost1,costBoth)*1ll*(need1-need2);
        }
        return ans;
    }
};