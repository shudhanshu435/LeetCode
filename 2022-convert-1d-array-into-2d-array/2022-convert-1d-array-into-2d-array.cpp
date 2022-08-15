class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        vector<vector<int>>vec;
        vector<int>v;
        int siz=original.size();
        if((m*n)!=siz)return {};
        int k=0;
        for(int i=0;i<siz;i++){
            if(k<n){
                v.push_back(original[i]);
                k++;
            }
            else{
                k=0;
                vec.push_back(v);
                v.clear();
                i--;
            }
        }
        vec.push_back(v);
        return vec;
    }
};