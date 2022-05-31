class Solution {
public:
    bool hasAllCodes(string s, int k) {
        if(s.length()<k)return 0;
        int ans = 1<<k;
        set<string>ss;
        for(int i=0;i<s.length()-k+1;i++){
            string str = s.substr(i,k);
              set<string>::iterator it = ss.find(str);
                // Check if iterator it is valid
                if (it != ss.end())continue;
            else{
                ss.insert(str);
                ans--;
            }
            
            if(ans==0)return 1;
            
        }
        return 0;
        
    }
};