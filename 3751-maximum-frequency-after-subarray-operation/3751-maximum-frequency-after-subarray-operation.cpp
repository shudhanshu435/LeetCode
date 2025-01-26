class Solution {
public:
    int kadane(vector<int>a){
        int c=0,ans=0;
        for(int i:a){
            c+=i;
            ans=max(ans,c);
            if(c<0)c=0;
        }
        return ans;
    }
    int maxFrequency(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>pre[51];
        int ans=0;
        for(int i=0;i<n;i++){
            if(nums[i]==k)ans++;
            for(int j=0;j<=50;j++){
                if(j==k)continue;
                if(nums[i]==k)pre[j].push_back(-1);
                else if(nums[i]==j)pre[j].push_back(1);
                else pre[j].push_back(0);
            }
        }
        int res=ans;
        for(int i=0;i<=50;i++)ans=max(ans,res+kadane(pre[i]));
        return ans;
    }
};

// 1  1  1  1  1  1
// 1  2  3  4  5  6
// 0 -1 -2 -3 -4 -5