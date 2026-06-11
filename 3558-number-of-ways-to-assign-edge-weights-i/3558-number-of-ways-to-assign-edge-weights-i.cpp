class Solution {
public:
    int mod=1000000007;
    long long modexpo(long long a, long long b){
        long long res=1;
        while(b>0){
            if(b&1){
                res=(res*a)%mod;
            }
            a=(a*a)%mod;
            b/=2;
        }
        return res%mod;
    }
    int assignEdgeWeights(vector<vector<int>>& edges) {
        unordered_map<int,vector<int>>mp;
        for(auto &i:edges){
            int u=i[0];
            int v=i[1];
            mp[u].push_back(v);
            mp[v].push_back(u);
        }
        queue<int>q;
        q.push(1);
        vector<bool>v(100001,0);
        // v[1]=1;
        int cnt=0;
        while(!q.empty()){
            int k=q.size();
            while(k--){
                int node=q.front();
                q.pop();
                if(v[node])continue;
                v[node]=1;
                for(auto &i:mp[node]){
                    if(!v[i]){
                        q.push(i);
                    }
                }
            }
            cnt++;
        }
        // cout<<cnt<<endl; // this cnt is max length of tree
        
        // now simply we have to count total no of different way to arrange 1's and 2's of on cnt-1 place such that the sum is even, because 1 root is fixed, so left sum will be even
        
        //when we'll analyze the pattern of counting---we'll see for length n, total way is 2^(n-1)

        // now here also n-1 can be larger for which it 2^(n-1) can be even more larger, so we'll use modular exponentiation.

        return modexpo(2,cnt-2);

        // return 0;
    }
};