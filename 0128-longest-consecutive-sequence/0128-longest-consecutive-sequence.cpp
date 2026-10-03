class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>s(nums.begin(),nums.end());
        int ans=0;
        for(int i:s){
            if(s.find((long long)i-1)==s.end()){
                int c=1; long long m=i;
                while(s.find(m+1)!=s.end()){
                    c++;
                    m++;
                }
                ans=max(ans,c);
            }
        }
        return ans;

    }
};