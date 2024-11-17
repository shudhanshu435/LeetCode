class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        vector<int>diff(n+1,0);
        diff[0]=nums[0];
        for(int i=1;i<n;i++){
            diff[i]=nums[i]-nums[i-1]; //difference array for range query problem
        }
        for(auto i:diff)cout<<i<<" ";
        cout<<endl;
        for(auto i:queries){
            int a=i[0];
            int b=i[1];
            diff[a]-=1;
            diff[b+1]+=1;
        }
        if(diff[0]>0)return 0;
        for(int i=1;i<diff.size()-1;i++){
            diff[i]=diff[i]+diff[i-1];
            if(diff[i]>0)return 0;
        }

        return 1;
    }
};