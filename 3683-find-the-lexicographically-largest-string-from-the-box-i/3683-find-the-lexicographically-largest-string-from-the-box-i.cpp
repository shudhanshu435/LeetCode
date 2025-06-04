class Solution {
public:
    string answerString(string word, int numF) {
        if(numF==1)return word;
        char ch='a';
        int n=word.length();
        for(int i=0;i<n;i++){
            if(word[i]>ch)ch=char(word[i]);
        }
        vector<int>v;
        for(int i=0;i<n;i++){
            if(word[i]==ch)v.push_back(i);
        }
        int len=n-numF+1;
        string ans="";
        for(int i=0;i<v.size();i++){
            string ss=word.substr(v[i],len);
            if(ss>ans)ans=ss;
        }
        
        // for(auto i:v)cout<<i<<" ";
        // cout<<endl;
        return ans;
    }
};