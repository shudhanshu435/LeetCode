class Solution {
public:
    int secondHighest(string s) {
        string nums="";
        for(int i=0;i<s.length();i++){
            if(s[i]>=48 && s[i]<=57)nums+=s[i];
        }
        int m=-1;
        sort(nums.begin(),nums.end());
        reverse(nums.begin(),nums.end());
        for(int i=1;i<nums.length();i++){
            if(nums[i]!=nums[i-1]){m=nums[i]-48;break;}
        }
        return m;
    }
};