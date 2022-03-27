class Solution {
public:
     
      int lin(vector<int>vec,int n){
          int ans=0;
          for(int i=0;i<vec.size();i++){
              if(vec[i]==n){
                  ans=i;
                  break;
              }
          }
          return ans;
      }
        vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<int>vec,tec,rec;
        int cnt;
        for(int i=0;i<mat.size();i++){
            cnt=0;
            for(int j=0;j<mat[0].size();j++){
                if(mat[i][j]==1)cnt++;
                else break;
            }
            vec.push_back(cnt);
        }
            
        tec=vec;
        sort(tec.begin(),tec.end());
        for(int i=0;i<k;i++){
            int m=lin(vec,tec[i]);
            vec[m]=101;
            rec.push_back(m);
        }

        return rec;
        }
    
};

