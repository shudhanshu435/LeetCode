class Solution {
public:
    long long findScore(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>vec;
        for(int i=0;i<nums.size();i++){
            vec.push_back({nums[i],i});
        }

        sort(vec.begin(),vec.end());
        long long score=0;
        vector<bool>visited(n,true);
        for(int i=0;i<nums.size();i++){
            int ele=vec[i][0];
            int ind=vec[i][1];
            if(visited[ind]==true){
                score+=ele;
                visited[ind]=false;
                if(ind-1>=0)visited[ind-1]=false;
                if(ind+1<n)visited[ind+1]=false;
            }
        }
        return score;
    }
};