class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        int n=nums.size();
        vector<int>big;
        for(int i=0;i<n;i++){
            if(nums[i]>right)big.push_back(i);
        }
        big.push_back(n);
        // for(auto i:big)cout<<i<<" ";
        // 0 2 4
        int l=0;
        long long non=0;
        for(int i=0;i<big.size();i++){
            int r=big[i];
            int cnt=0;
            vector<int>vv;
            for(;l<r;l++){
                if(nums[l]<left){
                    cnt++;
                }
                else{
                    if(cnt!=0)vv.push_back(cnt);
                    cnt=0;
                }
            }
            if(cnt!=0)vv.push_back(cnt);
            l=r+1;
            for(auto &v:vv){
                // cout<<v<<" ";
                non+=(v*1ll*(v+1)/2);
            }
        }
        // cout<<non<<endl;

        int kk=-1;
        long long pos=0;
        for(int i=0;i<big.size();i++){
            int dif=big[i]-kk-1;
            pos+=(dif*1ll*(dif+1)/2);
            kk=big[i];
        }
        return pos-non;
    }
};