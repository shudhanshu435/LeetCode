class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        vector<int>vec;
        vec.push_back(first);
        for(int i=0;i<encoded.size();i++){
            first = (first)^(encoded[i]);
            vec.push_back(first);
        }
        return vec;
    }
};