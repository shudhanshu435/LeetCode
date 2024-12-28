class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int>v;
        vector<int>vec(26,0),tec(26,0);
        int pn=p.length();
        int sn=s.length();
        if(sn<pn)return v;

        for(int i=0;i<pn;i++){
            vec[p[i]-'a']++;
            tec[s[i]-'a']++;
        }

        if(vec==tec)v.push_back(0);

        int k=0;
        for(int i=pn;i<sn;i++){
            tec[s[i]-'a']+=1;
            tec[s[k++]-'a']-=1;
            if(tec==vec)v.push_back(k);
        }

        return v;
    }
};