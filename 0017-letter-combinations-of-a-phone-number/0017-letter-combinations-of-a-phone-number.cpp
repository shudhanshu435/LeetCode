class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<pair<char,string>>vp={{'2',"abc"},{'3',"def"},{'4',"ghi"},{'5',"jkl"},{'6',"mno"},{'7',"pqrs"},{'8',"tuv"},{'9',"wxyz"}};
        vector<string>v;
        if(digits.size()==0)return {};
        if(digits.size()==1){
            for(auto &i:vp[(digits[0]-'0')-2].second){
                string s;
                s+=i;
                v.push_back(s);
            }
            return v;
        }
        if(digits.size()==2){
            for(auto &i:vp[(digits[0]-'0')-2].second){
                string s;
                s+=i;
                for(auto &j:vp[(digits[1]-'0')-2].second){
                    s+=j;
                    v.push_back(s);
                    s.pop_back();
                }
                
            }
            return v;
        }

        if(digits.size()==3){
            for(auto &i:vp[(digits[0]-'0')-2].second){
                string s;
                s+=i;
                for(auto &j:vp[(digits[1]-'0')-2].second){
                    s+=j;
                    for(auto &k:vp[(digits[2]-'0')-2].second){
                        s+=k;
                        v.push_back(s);
                        s.pop_back();
                    }
                    s.pop_back();
                }
            }
            return v;
        }

        if(digits.size()==4){
            for(auto &i:vp[(digits[0]-'0')-2].second){
                string s;
                s+=i;
                for(auto &j:vp[(digits[1]-'0')-2].second){
                    s+=j;
                    for(auto &k:vp[(digits[2]-'0')-2].second){
                        s+=k;
                        for(auto &m:vp[(digits[3]-'0')-2].second){
                            s+=m;
                            v.push_back(s);
                            s.pop_back();
                        }
                        s.pop_back();
                    }
                    s.pop_back();
                }
            }
            return v;
        }
        return {};
    }
};