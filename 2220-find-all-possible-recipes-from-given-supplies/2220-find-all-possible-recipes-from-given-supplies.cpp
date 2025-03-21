// class Solution {
// public:
//     vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ing, vector<string>& supplies) {
//         unordered_map<string,bool>sup;
//         vector<string>ans;
//         for(auto i:supplies)sup[i]=1;
//         for(int i=0;i<recipes.size();i++){
//             bool nt=false;
//             for(auto j:ing[i]){
//                 // cout<<j;
//                 // cout<<endl;
//                 if(sup[j])continue;
//                 else{
//                     nt=true;break;
//                 }
//             }
//             if(nt)continue;
//             else{
//                 ans.push_back(recipes[i]);
//                 sup[recipes[i]]=1;
//             }
//         }
//         return ans;
//     }
// };


class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_set<string> available(supplies.begin(), supplies.end());
        unordered_map<string, vector<string>> rec;
        vector<string> res;
        for (int i = 0; i < recipes.size(); i++)
            rec[recipes[i]] = ingredients[i];
        bool chk = true;
        while (chk) {
            chk = false;
            vector<string> newItems;
            for (auto& r : recipes) {
                if (available.count(r))
                    continue;
                bool can = true;
                for (string& ing : rec[r]) {
                    if (!available.count(ing)) {
                        can = false;
                        break;
                    }
                }
                if (can) {
                    newItems.push_back(r);
                    available.insert(r);
                    chk = true;
                }
            }
            for (string& r : newItems)
                res.push_back(r);
        }
        return res;
    }
};