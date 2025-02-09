class Solution {
public:
    int maxi=100000;
    vector<int> assignElements(vector<int>& gr, vector<int>& ele) {
        int n=gr.size();
        vector<int>ans(n,-1);
        vector<int>ind(maxi+1,-1);
        for(int i=0;i<ele.size();i++){
            if(ind[ele[i]]==-1)ind[ele[i]]=i;
        }
        for(int i=0;i<n;i++){
            int curr=100003;
            for(int k=1;k*k<=gr[i];k++){
                if(gr[i]%k==0){
                    if(ind[k]!=-1 and ind[k]<curr)curr=ind[k];
                    if(ind[gr[i]/k]!=-1 and ind[gr[i]/k]<curr)curr=ind[gr[i]/k];
                }
            }
            if(curr!=100003)ans[i]=curr;
            else ans[i]=-1;
        }
        return ans;
    }
};