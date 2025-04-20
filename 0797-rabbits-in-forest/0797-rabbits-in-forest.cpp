class Solution {
public:
    int numRabbits(vector<int>& a) {
        unordered_map<int,int>mp;
        for(auto i:a)mp[i]++;
        int ans=0;
        for(auto i:mp){
            int a=i.first;
            int b=i.second;
            b=ceil((double)b/(a+1));
            ans+=b*(a+1);
        }
        return ans;
    }
};