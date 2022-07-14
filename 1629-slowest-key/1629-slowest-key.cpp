class Solution {
public:
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {
        int m=releaseTimes[0];
        for(int i=1;i<releaseTimes.size();i++){
            int dif=releaseTimes[i]-releaseTimes[i-1];
            if(dif>m)m=dif;
        }
        string s="";
        if(releaseTimes[0]==m)s+=keysPressed[0];
        for(int i=1;i<releaseTimes.size();i++){
            int dif=releaseTimes[i]-releaseTimes[i-1];
            if(dif==m)s+=keysPressed[i];
        }
        sort(s.begin(),s.end());
        return s[s.size()-1];
    }
};