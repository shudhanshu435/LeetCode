class Solution {
public:
    int maximumLengthSubstring(string s) {
        int left = 0;
        int right = 0;

        int maxm=INT_MIN;

        unordered_map<char,int>mp;

        while (right<s.size()){
            mp[s[right]]+=1;

            while(mp[s[right]]>2){
                mp[s[left]]-=1;
                left++;
            }

            maxm=max(maxm,right-left+1);
            right++;
        }

        return maxm;
    }
};