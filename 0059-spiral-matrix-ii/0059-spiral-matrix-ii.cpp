class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>>v(n, vector<int>(n,0));
        int k=0,m=0,p=0,s=0,h=n+1/2,ele=1;
        while(1){
            for(int i=k;i<n-k;i++){
                v[k][i]=ele++;
            }
            k++;
            if(n&1){
                if(v[n/2][n/2]!=0)break;
            }
            ele--;
            if(n%2==0){
                if(v[n/2][(n/2)-1]!=0)break;
            }
            for(int i=m;i<n-m;i++){
                v[i][n-1-m]=ele++;
            }
            m++;
/*
            (0,0) (0,1) (0,2) (0,3) (0,4) 0,5
            (1,0) (1,1) (1,2) (1,3) (1,4) 1,5
            (2,0) (2,1) (2,2) (2,3) (2,4) 2,5
            (3,0) (3,1) (3,2) (3,3) (3,4) 3,5
            (4,0) (4,1) (4,2) (4,3) (4,4) 4,5
             5,0   5,1   5,2   5,3   5,4  5,5


             [[1,2,3,  4],
             [18,13,14,5],
             [17,16,15,6],
             [16,9,8,  7]]
*/
            ele--;
            for(int i=n-1-p;i>=p;i--){
                v[n-1-p][i]=ele++;
            }
            p++;

            cout<<ele<<endl;
            ele--;
            for(int i=n-1-s;i>=s+1;i--){
                v[i][s]=ele++;
            }
            s++;
        }
        return v;
    }
};

