class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n=A.size();
        vector<int>v;
        set<int>s;
        for(int i=0;i<n;i++){
            s.insert(A[i]);
            s.insert(B[i]);
            v.push_back((i+1)*2-s.size());
        }
        return v;
    }
};