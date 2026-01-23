class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        using ll=long;
        int n=nums.size();
        if(n==1) return 0;
        vector<ll> num;
        for(int i=0;i<n;i++) num.push_back(nums[i]);

        set<pair<ll,int>> st;
        vector<int> prv(n),nxt(n);
        for(int i=0;i<n;i++){
            nxt[i]=i+1;
            prv[i]=i-1;
        }
        int violation=0;
        for(int i=0;i<n-1;i++){
            st.insert({num[i]+num[i+1],i});
            violation+=(num[i]>num[i+1]);
        }
        int cnt=0;
        while(violation){
            auto it=*st.begin();
            ll sum=it.first,idx=it.second;
            int nxtIdx=nxt[idx],prvIdx=prv[idx],nextnext=nxt[nxtIdx];
            

            if(num[idx]>num[nxtIdx]) violation--;
            st.erase(it);

            if(prvIdx>=0){
                if(num[prvIdx]>num[idx]) violation--;
                st.erase({num[prvIdx]+num[idx],prvIdx});
            }
            if(nextnext<n){
                if(num[nxtIdx]>num[nextnext]) violation--;
                st.erase({num[nxtIdx]+num[nextnext],nxtIdx});
            }

            num[idx]=num[idx]+num[nxtIdx];
            nxt[idx]=nextnext;

            if(prvIdx>=0){
                if(num[prvIdx]>sum) violation++;
                st.insert({num[prvIdx]+sum,prvIdx});
            }
            if(nextnext<n){
                if(sum>num[nextnext]) violation++;
                st.insert({num[nextnext]+sum,idx});
                prv[nextnext]=idx;
            }
            cnt++;
        }
        return cnt;
    }
};