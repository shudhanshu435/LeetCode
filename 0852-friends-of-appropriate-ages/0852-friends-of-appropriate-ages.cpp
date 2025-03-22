class Solution {
public:
    bool req(int a, int b){
        return !(b<=0.5*a+7 or b>a or (b>100 and a<100));
    }
    int numFriendRequests(vector<int>& ages) {
        unordered_map<int,int>mp;
        for(auto &i:ages)mp[i]++;
        int ans=0;
        for(auto &i:mp){
            for(auto &j:mp){
                if(req(i.first,j.first))ans+=i.second*(j.second-(i.first==j.first?1:0));
            }
        }
        return ans;
    }
};