class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& dd) {
        vector<int>ev,t;
        set<int>vec;
        int n=dd.size();
        for(int i=0;i<dd.size();i++){
            if(dd[i]%2==0){
                if(find(ev.begin(),ev.end(),dd[i])==ev.end()){
                    ev.push_back(dd[i]);
                    t.push_back(i);
                }
            }
        }
        for(auto i:t){
            int num=dd[i];
            bool b=1;
            for(int j=0;j<n;j++){
                if(j!=i and dd[j]!=0){
                    for(int k=0;k<n;k++){
                        if(k!=i and k!=j){
                            int nm=dd[j]*100+dd[k]*10+dd[i];
                            vec.insert(nm);
                        }
                    }
                }
            }
        }
        vector<int>res(vec.begin(),vec.end());
        sort(res.begin(),res.end());
        return res;
    }
};