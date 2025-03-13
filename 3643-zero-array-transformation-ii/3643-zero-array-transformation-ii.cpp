class Solution {
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& qq) {
        int n=nums.size();
        
        vector<long long>v(n+1,0ll);
        long long sum=accumulate(nums.begin(),nums.end(),0ll);
        if(sum==0)return 0;
        long long i=0,j=qq.size()-1,ans=-1;
        while(i<=j){
            long long mid=j-(j-i)/2;
            fill(v.begin(), v.end(), 0ll);
            for(long long x=0;x<=mid;x++){
                // cout<<x<<endl;
                // cout<<qq[x][0]<<" rrrr "<<qq[x][2]<<endl;
                v[qq[x][0]]+=qq[x][2];
                v[qq[x][1]+1]-=qq[x][2];
            }
            bool f=true;
            vector<long long>pref(n);
            pref[0]=v[0];
            if(nums[0]>pref[0])f=false;
            else{
                for(long long i=1;i<n;i++){
                    pref[i]=v[i]+pref[i-1];
                    if(nums[i]>pref[i]){
                        f=false;break;
                    }
                }
            }
            if(!f){
                i=mid+1;
            }
            else{
                ans=mid+1;
                j=mid-1;
            }
        }
        return ans;




        // vector<vector<int>>v;
        // int maxi=0;
        // for(int i=0;i<n;i++){
        //     int sum=0;
        //     int cnt=0;
        //     bool f=true;
        //     if(nums[i]!=0){
        //         for(auto q:queries){
        //             if(i>=q[0] and i<=q[1]){
        //                 sum+=q[2];
        //             }
        //             cnt++;
        //             if(sum>=nums[i]){
        //                 maxi=max(maxi,cnt);
        //                 f=false;
        //                 break;
        //             }
        //         }
        //         if(f)return -1;
        //     }
        // }
        // return maxi;
    }
};