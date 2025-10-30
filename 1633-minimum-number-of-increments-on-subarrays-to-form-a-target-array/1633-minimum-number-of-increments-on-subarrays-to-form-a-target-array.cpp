class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int ans=0;
        int prev=0;
        for(auto &i:target){
            if(i>prev)ans+=i-prev;
            prev=i;
        }
        return ans;
    }
};