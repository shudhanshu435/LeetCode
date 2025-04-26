class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        if(minK>maxK)return 0;
        vector<int>v;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]==minK or nums[i]==maxK)v.push_back(nums[i]);
            else if(nums[i]<minK or nums[i]>maxK)v.push_back(-1);
            else v.push_back(0);
        }
        // for(auto i:v)cout<<i<<' ';

        vector<int>mi,mx,nt;
        for(int i=0;i<n;i++){
            if(v[i]==minK)mi.push_back(i);
            if(v[i]==maxK)mx.push_back(i);
            if(v[i]==-1)nt.push_back(i);
        }
        mi.push_back(n);
        mx.push_back(n);
        nt.push_back(n);

        // 1 0 5 0 -1 5
        // mi- 0 -6
        // mx- 2 5 -6
        // not- 4 -6

        // 1 1 1 1
        // mi- 0 1 2 3 -4
        // mx- 0 1 2 3 -4
        // not- -4
        long long ans=0;
        // for(auto i:mx)cout<<i<<' ';
        // cout<<endl;
        // for(auto i:nt)cout<<i<<' ';
        // cout<<endl;
        for(int i=0;i<n;i++){
            if(v[i]==minK){
                auto it=lower_bound(mx.begin(),mx.end(),i);
                auto itt=lower_bound(nt.begin(),nt.end(),i);
                if(*it<*itt){
                    ans+=(*itt-*it);
                }
                // cout<<*it<<" "<<*itt<<endl;
                // cout<<ans<<endl;
            }
            else if(v[i]==0){
                auto it=lower_bound(mi.begin(),mi.end(),i);
                auto itt=lower_bound(mx.begin(),mx.end(),i);
                int maxi=max(*it,*itt);
                auto it2=lower_bound(nt.begin(),nt.end(),i);
                if(*it2>maxi)ans+=*it2-maxi;
            }
            else if(v[i]==maxK){
                auto it=lower_bound(mi.begin(),mi.end(),i);
                auto itt=lower_bound(nt.begin(),nt.end(),i);
                int ix1=it-mi.begin();
                int ix2=itt-nt.begin();
                if(*it<*itt){
                    ans+=(*itt-*it);
                }
            }
            else continue;
        }


        return  ans;
    }
};
/*

    

*/