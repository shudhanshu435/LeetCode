class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n=nums.size();
        vector<long long>ps(n,0);
        ps[0]=nums[0];
        for(int i=1;i<n;i++){
            ps[i]=nums[i]+ps[i-1];
        }
        vector<long long>ss(n,0);
        ss[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--){
            ss[i]=nums[i]+ss[i+1];
        }

        // for(auto i:ps)cout<<i<<" ";
        // cout<<endl;
        // for(auto i:ss)cout<<i<<" ";
        int cnt=0;
        for(int i=0;i<n-1;i++){
            if(ps[i]>=ss[i+1])cnt++;
        }
        return cnt;

        // return 3;

    }
};

/*

10, 4, -8, 7

ps - 10 , 14, 6, 13
ss - 13 , 3 , -1, 7



*/