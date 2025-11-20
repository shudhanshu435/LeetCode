class Solution {
public:
    static bool cmp(const vector<int>&a,const vector<int> &b){
        if(a[1]!=b[1])return a[1]<b[1];
        return a[0]>b[0];
    }
    int intersectionSizeTwo(vector<vector<int>>& inv) {
        sort(inv.begin(),inv.end(),cmp);
        vector<int>select;

        for(auto &v:inv){
            int a=v[0];
            int b=v[1];
            int cnt=0;
            for(auto &c:select){
                if(c>=a and c<=b)cnt++;
                if(cnt==2)break;
            }

            while(cnt<2){
                select.push_back(b);
                b--;
                cnt++;
            }
        }
        return select.size();
    }
};