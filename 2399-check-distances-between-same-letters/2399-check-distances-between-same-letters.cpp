class Solution {
public:
    bool checkDistances(string s, vector<int>& distance) {
        int hss[26]={0};
        int res=0;
        for(int i=0;i<s.length();i++){
            if(hss[s[i]-97]==0){
                hss[s[i]-97]=i;
            }
            else hss[s[i]-97]=i-hss[s[i]-97];
            
        }
        for(int i=0;i<26;i++){
            cout<<hss[i]-1<<" ";
            
        }
        for(int i=0;i<26;i++){
           if(hss[i]-1==-1)continue;
           else if((distance[i]==(hss[i]-1)))continue;
           else{
               res++;break;
           } 
        }
        
        if(res==0)
        return 1;
        else return 0;
    }
};

