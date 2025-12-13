class Solution {
public:
    bool isTrue(string &s){
        if(s.size()==0)return false;
        for(auto &i:s){
            if((i>='a' and i<='z') or (i>='A' and i<='Z') or (i>='0' and i<='9') or i=='_')continue;
            else return false;
        }
        return true;
    }
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        int n=code.size();
        vector<pair<string,string>>vp;
        for(int i=0;i<n;i++){
            if(isActive[i] and (businessLine[i]=="electronics" or businessLine[i]=="pharmacy" or businessLine[i]=="grocery" or businessLine[i]=="restaurant") and isTrue(code[i])){
                vp.push_back({businessLine[i],code[i]});
            }
        }
        sort(vp.begin(),vp.end());
        vector<string>ans;
        for(auto &i:vp){
            // cout<<i.first<<" "<<i.second<<endl;
            ans.push_back(i.second);
        }
        return ans;
    }
};