class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n=nums.size();
        int ans=INT_MAX;
        for(int i=1;i<=100;i++){
            vector<int>v;
            for(int j=0;j<n;j++){
                if(i==nums[j])v.push_back(j);
                int s=v.size();
                if(s>=3){
                    ans=min(ans,abs(v[s-1]-v[s-2])+abs(v[s-2]-v[s-3])+abs(v[s-1]-v[s-3]));
                }
            }
        }
        return (ans==INT_MAX)?-1:ans;
    }
};