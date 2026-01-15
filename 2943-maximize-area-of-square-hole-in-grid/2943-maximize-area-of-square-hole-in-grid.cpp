class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hh, vector<int>& vv) {
        sort(hh.begin(),hh.end());
        sort(vv.begin(),vv.end());
        int maxi=2;
        int cur=0;
        for(int i=1;i<hh.size();i++){
            if(hh[i]-hh[i-1]==1){
                cur++;
            }
            else{
                maxi=max(maxi,cur+2);
                cur=0;
            }
        }
        maxi=max(maxi,cur+2);
        int maxi2=2;
        int cur2=0;
        for(int i=1;i<vv.size();i++){
            if(vv[i]-vv[i-1]==1){
                cur2++;
            }
            else{
                maxi2=max(maxi2,cur2+2);
                cur2=0;
            }
        }
        maxi2=max(maxi2,cur2+2);
        // cout<<maxi<<" "<<maxi2<<endl;
        return min(maxi,maxi2)*min(maxi,maxi2);
    }
};