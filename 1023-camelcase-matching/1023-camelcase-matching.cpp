class Solution {
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        vector<bool>ans;
        for(auto &i:queries){
            int ii=0;
            int j=0;
            
            int q=i.size();
            int p=pattern.length();

            if(p>q){
                ans.push_back(0);
                continue;
            }
            bool b=1;
            while(ii<q){
                if(j<p and i[ii]==pattern[j]){
                    ii++;j++;
                }
                else{
                    if(i[ii]>='a' and i[ii]<='z')ii++;
                    else {
                        ii++;
                        ans.push_back(0);
                        b=0;
                        break;
                    }
                }
            }
            if(j!=p and b)ans.push_back(0);
            else if(b)ans.push_back(1);
            b=1;

        }
        return ans;

    }
};