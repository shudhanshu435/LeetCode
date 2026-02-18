class Solution {
public:
    long long func(vector<int>&vec){
        int n=vec.size();
        // for(auto i:vec)cout<<i<<" ";
        // cout<<endl;
        if(n==0)return 0;
        if(n==1)return vec[0];
        long long p1=vec[0];
        long long p2=max(vec[0],vec[1]);
        for(int i=2;i<n;i++){
            long long curr=max(p2,p1+vec[i]);
            p1=p2;
            p2=curr;
        }
        return p2;

    }
    long long rob(vector<int>& nums, vector<int>& colors) {
        long long ans=0;
        int n=colors.size();
        long long maxi=0;
        colors.push_back(-1);
        vector<int>v;
        for(int i=0;i<n;i++){
            if(colors[i]!=colors[i+1]){
                v.push_back(nums[i]);
                ans+=func(v);
                v.clear();
            }
            else{
                v.push_back(nums[i]);
            }
        }
        return ans;
    }
};