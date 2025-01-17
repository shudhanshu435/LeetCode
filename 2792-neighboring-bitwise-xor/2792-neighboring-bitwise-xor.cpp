class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int n=derived.size();
        vector<int>v(n),t(n);
        v[0]=1;
        t[0]=0;
        for(int i=0;i<n-1;i++){
            if(derived[i]==1){
                if(v[i]==0)v[i+1]=1;
                else v[i+1]=0;
                if(t[i]==1)t[i+1]=0;
                else t[i+1]=1;
            }
            else{
                if(v[i]==0)v[i+1]=0;
                else v[i+1]=1;
                if(t[i]==1)t[i+1]=1;
                else t[i+1]=0;
            }
        }
        if((v[n-1]^v[0]==derived[n-1]) or (t[n-1]^t[0]==derived[n-1]))return 1;
        return 0;
    }
};