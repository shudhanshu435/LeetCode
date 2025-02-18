class Solution {
public:
    long long minimumCost(int m, int n, vector<int>& hori, vector<int>& veri) {
        sort(hori.rbegin(), hori.rend());
        sort(veri.rbegin(), veri.rend());
        int i=0,j=0;
        int t1=0,t2=0;
        int h=1,v=1;
        long long cost=0;

        while(i<hori.size() and j<veri.size()){
            int n1=hori[i];
            int n2=veri[j];
            if(n1>n2){
                cost+=n1*v;
                h++;
                i++;
            }
            else{
                cost+=n2*h;
                v++;
                j++;
            }
        }
        while(i<hori.size())cost+=(hori[i++]*v);
        while(j<veri.size())cost+=(veri[j++]*h);
        
        return cost;
    }
};