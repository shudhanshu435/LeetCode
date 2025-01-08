class Solution {
public:
    bool isPrefixAndSuffix(string a, string b){
        int s=a.size();
        int c=b.size();
        if(s<=c){
            if(b.substr(0,s)==a and b.substr(c-s)==a)return 1;
            return 0;
        }
        else return 0;
    }

    int countPrefixSuffixPairs(vector<string>& words) {
        int cnt=0;
        int n=words.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(isPrefixAndSuffix(words[i],words[j]))cnt++;
            }
        }
        return cnt;
    }
};