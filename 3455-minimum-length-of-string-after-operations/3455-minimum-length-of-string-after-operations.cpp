class Solution {
public:
    int minimumLength(string s) {
        int cnt=0;
        vector<int>vec(26,0);
        for(auto i:s){
            vec[i-'a']++;
        }
        for(int i=0;i<26;i++){
            if(vec[i]!=0){
                if(vec[i]&1)cnt+=1;
                else cnt+=2;
            }
        }

        return cnt;
    }
};