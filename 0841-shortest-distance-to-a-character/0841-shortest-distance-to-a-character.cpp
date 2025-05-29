class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        vector<int>v,a;
        int n=s.length();
        for(int i=0;i<n;i++){
            if(s[i]==c)v.push_back(i);
        }
        int k=0;
        for(int i=0;i<n;i++){
            if(i<=v[k]){
                a.push_back(v[k]-i);
            }
            else if(k+1<v.size() and i<=v[k+1]){
                a.push_back(min(i-v[k],v[k+1]-i));
                if(i==v[k+1]){
                    k++;
                }
            }
            else a.push_back(i-v[k]);
        }
        return a;
    }
};

//  3, 5, 6, 11