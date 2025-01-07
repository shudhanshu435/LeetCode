class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        vector<string>vec;
        int n=words.size();
        for(int i=0;i<n;i++){
            int s=words[i].size();
            bool found=false;
            for(int j=0;j<n;j++){
                if(i!=j){
                    int m=words[j].size();
                    if(s<m){
                        for(int k=0;k<=m-s;k++){
                            string ss=words[j].substr(k,s);
                            if(ss==words[i]){
                                found=true;
                                break;
                            }
                        }
                        if(found){
                            vec.push_back(words[i]);
                            break;
                        }
                    }
                }
            }
            // if(found)vec.push_back(words[i]);
        }
        return vec;
    }
};