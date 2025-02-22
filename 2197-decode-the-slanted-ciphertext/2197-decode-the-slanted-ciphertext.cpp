class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        int len=encodedText.size();
        cout<<len<<endl;
        string ans="";
        // vector<vector<int>>vec()
        for(int i=0;i<len/rows;i++){
            int pos=i;
            while(pos<len){
                ans+=encodedText[pos];
                pos+=(len/rows)+1;
            }
        }
        while(!ans.empty() and ans.back()==' ')ans.pop_back();
        return ans;
    }
};

/*

i v e o - -
- - e e d -
- - l - t e
- - - o l c

*/