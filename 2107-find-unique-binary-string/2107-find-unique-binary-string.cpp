class Solution {
public:
    // void solve(string s, int n,unordered_map<string,int>& mp,string& ans){
    //     if(s.size()==n){
    //         if(mp[s]==0){
    //             ans=s;
    //         }
    //         return;
    //     }
    //     if(!ans.empty())return;

    //     s.push_back('0');
    //     solve(s,n,mp,ans);
    //     s.pop_back();

    //     s.push_back('1');
    //     solve(s,n,mp,ans);
    //     s.pop_back();
    // }
    
    // string dectobin(long long n, int size){
    //     string ans="";
    //     while(size--){
    //         if(n&1)ans+='1';
    //         else ans+='0';
    //         n/=2;
    //     }
    //     reverse(ans.begin(),ans.end());
    //     return ans;
    // }
    // long long bintodec(string& s){
    //     int n=s.length();
    //     long long ans=0;
    //     for(int i=0;i<n;i++){
    //         if(s[n-1-i]=='1')
    //             ans+=(1<<i);
    //     }
    //     return ans;
    // }
    string findDifferentBinaryString(vector<string>& nums) {
        // unordered_map<long long,int>mp;
        // for(auto i:nums){
        //     mp[bintodec(i)]++;
        // }
        // int n=nums.size();
        // long long i=0;
        // while(1){
        //     if(mp[i]==0){
        //         return dectobin(i,n);
        //     }
        //     i++;
        // }
        int n = nums.size();
        string ans;
        for (int i = 0; i < n; i++) {
            ans += (nums[i][i] == '0') ? '1' : '0';
        }
        return ans;
    }
};