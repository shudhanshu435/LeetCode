class Solution {
public:
    int maxFreqSum(string s) {
        vector<int>vec(26,0);
        for(auto &i:s)vec[i-'a']++;
        int v=0,c=0;
        for(int i=0;i<s.size();i++){
            char ch=s[i];
            if(vec[s[i]-'a']!=0){
                if(ch=='a' or ch=='i' or ch=='o' or ch=='e' or ch=='u')v=max(v,vec[s[i]-'a']);
                else if(vec[s[i]-'a']!=0)c=max(c,vec[s[i]-'a']);
            }
        }

        return v+c;
    }
};