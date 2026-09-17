class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int sum=0,s=0;
        int n=arr.size();
        vector<pair<int,int>>v;
        for(int i=0;i<n;i++){
            sum+=arr[i];
            while(sum>target){
                sum-=arr[s++];
            }
            if(sum==target){
                v.push_back({s,i});
            }
        }
        vector<int>d;
        for(auto i:v){
            d.push_back(i.second-i.first+1);
            // cout<<i.first<<" "<<i.second<<endl;
        }
        for(int i=d.size()-2;i>=0;i--){
            d[i]=min(d[i],d[i+1]);
        }
        // for(auto i:d){
        //     cout<<i<<endl;
        // }
        int ans=INT_MAX;
        for(auto [a,b]:v){
            auto it=upper_bound(v.begin(),v.end(),make_pair(b,INT_MAX));
            int ind =it-v.begin();
            // cout<<"ind "<<ind<<endl;
            if(ind<d.size())ans=min(ans,b-a+1+d[ind]);
        }
        if(ans==INT_MAX)return -1;
        return ans;
    }
};