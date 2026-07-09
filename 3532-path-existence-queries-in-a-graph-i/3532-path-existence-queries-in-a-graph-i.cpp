class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int>vec;
        vec.push_back(-1);
        for(int i=0;i<n-1;i++){
            if(nums[i+1]-nums[i]>maxDiff){
                vec.push_back(i);
            }
        }
        vec.push_back(n-1);
        vector<bool>ans;
        for(auto i:queries){
            int x=i[0];
            int y=i[1];
            if(x>y)swap(x,y);
            auto it=lower_bound(vec.begin(),vec.end(),y);
            int ind=it-vec.begin();
            if(vec[ind-1]<x)ans.push_back(true);
            else ans.push_back(false);
        }

        return ans;

    }
};