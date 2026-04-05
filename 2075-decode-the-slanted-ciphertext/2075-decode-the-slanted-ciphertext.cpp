class Solution {
public:
    string decodeCiphertext(string en, int rows) {
        int len=en.length();
        int col=len/rows;
        int k=0;
        vector<vector<char>>v(rows,vector<char>(col));
        for(int i=0;i<rows;i++){
            for(int j=0;j<col;j++){
                v[i][j]=en[k++];
            }
        }

        // for(auto i:v){
        //     for(auto j:i)cout<<j<<" ";
        //     cout<<endl;
        // }

        string ans="";
        for(int s=0;s<col;s++){
            int i=0,j=s;
            while(i<rows and j<col){
                ans+=v[i][j];
                i++;j++;
            }
        }
        while(!ans.empty() and ans.back()==' ')ans.pop_back();
        return ans;

    }
};