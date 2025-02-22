class Solution {
public:
    int minFlips(string target) {
        int cnt=0;
        int n=target.size();
        for(int i=0;i<n-1;i++){
            if(target[i]!=target[i+1])cnt++;
        }
        if(target[0]=='0')return cnt;
        return cnt+1;
    }
};
