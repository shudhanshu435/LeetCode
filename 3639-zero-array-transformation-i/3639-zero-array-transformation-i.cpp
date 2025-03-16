class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        vector<int>vec(n+1,0);
        for(auto query:queries){
            int q=query[0],r=query[1];
            vec[q]+=1;
            vec[r+1]-=1;
        }
        for(int i=1;i<=n;i++){
            vec[i]=vec[i]+vec[i-1];
        }
        bool is=true;
        for(int i=0;i<n;i++){
            if(nums[i]>vec[i]){
                is=false;break;
            }
        }
        return is;
    }
};