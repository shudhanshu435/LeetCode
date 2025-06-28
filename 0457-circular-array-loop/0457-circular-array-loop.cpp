class Solution {
public:
    bool circularArrayLoop(vector<int>& nums) {
        int n=nums.size();
        int p,i;
        bool ans=0;
        for(i=0;i<n;i++){
            int cnt=0;
            unordered_map<int,bool>mp;
            if(nums[i]<0)continue;
            int nex=i;
            while(1){
                if(mp[nex]==1){
                    p=1;
                    break;
                }
                mp[nex]=1;
                int g=nex;
                nex=(nex+nums[nex])%n;
                if(g==nex){
                    cnt=0;break;
                }
                if(nums[nex]>0)cnt++;
                else {
                    cnt=0;break;
                }
            }
            if(cnt>1 and p==1){
                ans=1;break;
            }
        }
        cout<<i;
        if(ans==true)return ans;
        p=0;
        for(int i=0;i<n;i++){
            int cnt=0;
            unordered_map<int,bool>mp;
            if(nums[i]>0)continue;
            int nex=i;
            while(1){
                if(mp[nex]==1){
                    p=1;
                    break;
                }
                mp[nex]=1;
                int g=nex;
                nex=(nex+nums[nex]%n+n)%n;
                if(g==nex){
                    cnt=0;break;
                }
                if(nums[nex]<0)cnt++;
                else {
                    cnt=0;break;
                }
            }
            if(cnt>1 and p==1){
                ans=1;break;
            }
        }
        cout<<i;
        return ans;
    }
};