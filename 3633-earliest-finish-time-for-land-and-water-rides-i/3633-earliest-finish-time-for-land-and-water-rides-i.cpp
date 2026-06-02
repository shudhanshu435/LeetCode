class Solution {
public:
    int earliestFinishTime(vector<int>& lt, vector<int>& ldt, vector<int>& wt, vector<int>& wdt) {
        int n=lt.size();
        int m=wt.size();
        int res=INT_MAX;
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                int landFin=lt[i]+ldt[i];
                int waterFin1=max(landFin,wt[j])+wdt[j];
                res=min(res,waterFin1);
    
                int waterFin=wt[j]+wdt[j];
                int landFin2=max(waterFin,lt[i])+ldt[i];
                res=min(res,landFin2);
            }
        }
        return res;
    }
};