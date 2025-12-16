class Solution {
public:
    vector<int> beautifulIndices(string s, string a, string b, int k) {
        vector<int>ind,rnd;
        int n=s.length();
        int aa=a.length();
        int bb=b.length();
        for(int i=0;i<n;i++){
            if(s.substr(i,aa)==a)ind.push_back(i);
        }
        for(int i=0;i<n;i++){
            if(s.substr(i,bb)==b)rnd.push_back(i);
        }
        //a - 16 , 33
        //b - 0 , 18
        int i=0,j=0;
        for(auto i:ind)cout<<i<<" ";
        cout<<endl;
        for(auto i:rnd)cout<<i<<" ";
        cout<<endl;

        vector<int>ans;
        while(i<ind.size() and j<rnd.size()){
            if(abs(ind[i]-rnd[j])<=k)ans.push_back(ind[i++]);
            else{
                if(ind[i]>rnd[j])j++;
                else i++;
            }
        }
        return ans;
    }
};