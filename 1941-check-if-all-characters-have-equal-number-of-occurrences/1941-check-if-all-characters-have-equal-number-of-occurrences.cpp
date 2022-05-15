class Solution {
public:
    bool areOccurrencesEqual(string s) {
        sort(s.begin(),s.end());
        int cnt=0;
        char ch=s[0];
        unordered_set<int>ss;
        for(int i=0;i<s.length();i++){
            if(s[i]==ch){
                cnt++;
                
            }else{
                cout<<cnt<<endl;
                ss.insert(cnt);
                cnt=0;
                ch=s[i];
                i--;
            }
        }ss.insert(cnt);
        cout<<ss.size()<<endl;
        if(ss.size()==1)return 1;
        else return 0;
    }
};