class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        vector<int>vec;
        for(int i=0;i<sentences.size();i++)
            {
            string ss=sentences[i];
            int cnt=0;
            for(int i=0;i<ss.length();i++){
                if(ss[i]==' ')cnt++;
            }
            vec.push_back(cnt);
        }sort(vec.begin(),vec.end());
        return vec[vec.size()-1]+1;
        
    }
};