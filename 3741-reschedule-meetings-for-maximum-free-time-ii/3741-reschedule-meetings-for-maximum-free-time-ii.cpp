class Solution {
public:
    int maxFreeTime(int et, vector<int>& st, vector<int>& en) {
        int ans=0;
        int n=st.size();
        vector<int>gap,spc;
        gap.push_back(st[0]-0);
        spc.push_back(en[0]-st[0]);
        for(int i=0;i<n-1;i++){
            spc.push_back(en[i+1]-st[i+1]);
            gap.push_back(st[i+1]-en[i]);
        }
        gap.push_back(et-en[n-1]);
        for(int i=0;i<n;i++){
            ans=max(ans,gap[i+1]+gap[i]);
        }
        // 0 6 1 0
        // 1 1 1
        int ss=gap.size();
        vector<int>pre(ss),suf(ss);
        pre[0]=gap[0];
        for(int i=1;i<ss;i++){
            pre[i]=max(pre[i-1],gap[i]);
        }
        suf[ss-1]=gap[ss-1];
        for(int i=ss-2;i>=0;i--){
            suf[i]=max(suf[i+1],gap[i]);
        }

        for(int i=0;i<n;i++){
            if((i-1>=0 and spc[i]<=pre[i-1]) or (i+2<=n and spc[i]<=suf[i+2])){
                ans=max(ans,gap[i]+gap[i+1]+spc[i]);
            }
        }
        return ans;
    }
};