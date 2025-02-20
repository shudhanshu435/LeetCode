class Solution {
public:
    void solve(string s, int n,unordered_map<string,int>& mp,string& ans){
        if(s.size()==n){
            if(mp[s]==0){
                ans=s;
            }
            return;
        }
        if(!ans.empty())return;

        s.push_back('0');
        solve(s,n,mp,ans);
        s.pop_back();

        s.push_back('1');
        solve(s,n,mp,ans);
        s.pop_back();
    }
    string findDifferentBinaryString(vector<string>& nums) {
        unordered_map<string,int>mp;
        for(auto i:nums)mp[i]++;
        int n=nums.size();
        string ans;
        solve("",n,mp,ans);

        return ans;
    }
};