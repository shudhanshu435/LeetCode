class Solution {
public:
    int mod=1e9+7;
    int threeSumMulti(vector<int>& arr, int target) {
        unordered_map<int,int>mp;
        sort(arr.begin(),arr.end());
        int n=arr.size();
        long long ans=0;
        for(int i=0;i<n-2;i++){
            for(int m=i+1;m<n;m++)mp[arr[m]]++;
            for(int j=i+1;j<n-1;j++){
                mp[arr[j]]--;
                ans=(ans+mp[target-(arr[i]+arr[j])])%mod;
                // cout<<ans<<endl;
                if(target-(arr[i]+arr[j])<arr[j])break;
            }
            mp.clear();
            // cout<<endl;
        }

        return ans;
    }
};