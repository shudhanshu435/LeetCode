class Solution {
public:
    int ret(string &s,char c1, char c2){
        unordered_map<int,int>mp;
        int diff=0;
        int ans=0;
        int kk=0;
        mp[0]=-1;
        int n=s.length();
        for(int i=0;i<n;i++){
            if(s[i]==c1)diff++;
            else if(s[i]==c2)diff--;
            if(s[i]!=c1 and s[i]!=c2){
                mp.clear();
                mp[0]=i;
                diff=0;
                continue;
            }
            if(s[i]==c1)diff++;
            else diff--;
            if(mp.count(diff))ans=max(ans,i-mp[diff]);
            else mp[diff]=i;
        }
        // cout<<"ss - "<<ans<<endl;
        return ans;
    }
    int longestBalanced(string s) {
        int n=s.length();
        int ans=0;
        int cnt=1;
        for(int i=0;i<n-1;i++){
            if(s[i+1]==s[i])cnt++;
            else{
                ans=max(ans,cnt);
                cnt=1;
            }
        }
        ans=max(ans,cnt);
        cout<<"sa - "<<ans<<endl;
        map<pair<int,int>,int>mp;
        int a=0,b=0,c=0;
        for(int i=0;i<n;i++){
            if(s[i]=='a')a++;
            else if(s[i]=='b')b++;
            else c++;
            if(mp[{a-b,b-c}]==0)mp[{a-b,b-c}]=i+1;
            if(a==0 or b==0 or c==0)continue;
            if(a-b==b-c and a-c==b-c)ans=max(ans,i+1);

            ans=max(ans,i+1-mp[{a-b,b-c}]);
            // cout<<"sa - "<<ans<<endl;
        }
        // cout<<"saaaaa - "<<ans<<endl;

        ans=max(ans,ret(s,'a','b'));
        // cout<<"s1 - "<<ans<<endl;
        ans=max(ans,ret(s,'a','c'));
        // cout<<"s2 - "<<ans<<endl;
        ans=max(ans,ret(s,'b','c'));
        // cout<<"s3 - "<<ans<<endl;


        return ans;
    }
};