class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dict) {
        vector<string>ans;
        for(auto &i : queries){
            for(auto &v : dict){
                int cnt=0;
                for(int it=0;it<i.length();it++){
                    if(i[it]!=v[it]){
                        cnt++;
                    }
                    if(cnt>2)break;
                }
                if(cnt<=2){
                    ans.push_back(i);break;
                }
            }
        }
        return ans;
    }
};