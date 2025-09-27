class Solution {
public:
    string majorityFrequencyGroup(string s) {
        unordered_map<char,int>mp;
        for(auto &i:s)mp[i]++;
        unordered_map<int,int>mp2;
        int maxi=0;
        for(auto &[a,b]:mp){
            mp2[b]++;
        }
        int num;
        for(auto &[a,b]:mp2){
            if(b > maxi || (b == maxi && a > num)){
                num=a;
                maxi=b;
            }
        }
        string ans="";
        for(auto &[a,b]:mp){
            if(b==num)ans+=a;
        }
        return ans;
    }
};