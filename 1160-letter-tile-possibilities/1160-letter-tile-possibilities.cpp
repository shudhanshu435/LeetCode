class Solution {
public:
    void recurr(string& s, string& tiles, vector<bool>& used, set<string>&st){
        if(s.size()!=0){
            st.insert(s);
        }

        for(int i=0;i<tiles.size();i++){
            if(used[i])continue;

            used[i]=true;
            s+=tiles[i];

            recurr(s,tiles,used,st);

            s.pop_back();
            used[i]=false;
        }

        // if(i==tiles.size())return;

        // recurr(s+tiles[i],i+1,tiles,st);
        // recurr(s,i+1,tiles,st);
    }
    int numTilePossibilities(string tiles) {
        int n=tiles.size();
        set<string>s;
        string ss="";
        vector<bool>used(tiles.size(),0);
        recurr(ss,tiles,used,s);
        return s.size();
    }
};