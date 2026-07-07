class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        vector<int>vec(26,0);
        for(int i=0;i<order.size();i++){
            vec[order[i]-'a']=i;
        }
        int n=words.size();
        for(int i=0;i<n-1;i++){
            string a=words[i];
            string b=words[i+1];
            int x=0,y=0;
            while(x<a.length() and y<b.length()){
                if(a[x]!=b[y]){
                    if(vec[a[x]-'a']>vec[b[y]-'a'])return 0;
                    break;
                }
                x++;y++;
                if(x==b.length() and a.length()>b.length())return 0;
            }
        }
        return 1;
    }
};