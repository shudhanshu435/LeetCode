class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        unordered_set<int>s;
        int n=nums.size();
        if(n%3!=0){
            s.insert(nums[n-1]);
            if(n%3==2){
                s.insert(nums[n-2]);
                if(s.size()==1)return (n/3)+1;
            }
        }
        for(int i=n-(n%3)-1;i>=0;i--){
            s.insert(nums[i]);
            if(s.size()!=n-i)return ceil((i+1)/3.0);
        }
        return 0;
    }
};