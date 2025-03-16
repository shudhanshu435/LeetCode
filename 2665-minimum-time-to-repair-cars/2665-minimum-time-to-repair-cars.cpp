class Solution {
public:
    bool pos(vector<int>&ranks, long long mid, int cars){
        long long sum=0;
        for(auto i:ranks){
            sum+=sqrt(mid/i);
            // cout<<sum<<endl;
            if(sum>=cars)return 1;
        }
        return 0;
    }
    long long repairCars(vector<int>& ranks, int cars) {
        long long l=*min_element(ranks.begin(),ranks.end());
        long long r=*max_element(ranks.begin(),ranks.end());
        r=l*1ll*cars*cars;
        l=1;
        // cout<<l<<" "<<r<<endl;
        sort(ranks.begin(),ranks.end());
        long long ans=0;
        while(l<=r){
            long long mid=r-(r-l)/2;
            if(pos(ranks,mid,cars)){
                // cout<<"s"<<endl;
                ans=mid;
                r=mid-1;
            }
            else l=mid+1;
        }
        return ans;
    }
};