class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<pair<int,string>>vec;
        vector<string>s;
        for(int i=0;i<names.size();i++){
            vec.push_back(make_pair(heights[i],names[i]));
        }
        sort(vec.rbegin(),vec.rend());
        for(int i=0;i<vec.size();i++){
            s.push_back(vec[i].second);
        }
        return s;
    }
};