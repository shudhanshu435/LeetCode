class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int n=nums.size();
        vector<int>vec(n+1,0),tec(n+1,0);
        vec[0]=0;
        for(int i=1;i<=n;i++){
            vec[i]=nums[i-1]+vec[i-1];
        }
        tec[n]=0;
        for(int i=n-1;i>=0;i--){
            tec[i]=nums[i]+tec[i+1];
        }
        int ans=0;

        for(auto i:vec){
            cout<<i<<" ";
        }
        cout<<endl;
        for(auto i:tec){
            cout<<i<<" ";
        }
        cout<<endl;
        

        for(int i=0;i<n;i++){
            if(nums[i]==0){
                if(vec[i]==tec[i+1])ans+=2;
                else if(abs(vec[i]-tec[i+1])==1)ans+=1;
            }
        }
        return ans;
    }
};