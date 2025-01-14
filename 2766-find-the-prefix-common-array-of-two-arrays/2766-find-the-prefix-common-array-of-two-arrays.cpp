class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        set<int>s;
        int maxi=0;
        vector<int>vec;
        int k=0;
        for(int i=0;i<A.size();i++){
            k+=2;
            s.insert(A[i]);
            s.insert(B[i]);
            vec.push_back(k-s.size());
        }
        return vec;

    }
};