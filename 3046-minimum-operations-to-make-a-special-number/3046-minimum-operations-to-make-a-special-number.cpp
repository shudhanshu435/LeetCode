class Solution {
public:
    int minimumOperations(string num) {
        int n=num.size();
        int j,k,z=0,ans=INT_MAX;
        for(int i=n-1;i>=0;i--){
            if(num[i]=='0'){
                z++;
                j=i-1;
                while(j>=0){
                    if(num[j]=='5' or num[j]=='0')break;
                    j--;
                }
                if(j>=0){
                    ans=min(ans,n-1-i+(i-j-1));
                    // cout<<ans<<endl;
                }
            }
        }
        for(int i=n-1;i>=0;i--){
            if(num[i]=='5'){
                j=i-1;
                while(j>=0){
                    if(num[j]=='2' or num[j]=='7')break;
                    j--;
                }
                if(j>=0){
                    ans=min(ans,n-1-i+(i-j-1));
                    // cout<<ans<<endl;
                }
            }
        }
        if(ans!=INT_MAX)return ans;
        if(z!=0)return n-1;
        return n;



    }
};