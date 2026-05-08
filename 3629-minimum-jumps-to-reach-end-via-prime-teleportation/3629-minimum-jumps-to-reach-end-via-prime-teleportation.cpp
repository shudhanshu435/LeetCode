class Solution {
public:
    vector<bool>prime;
    vector<bool> sieve(int limit) {
        prime.resize(limit+1,1);
        if(limit>=0)prime[0]=false;
        if(limit>=1)prime[1]=false;

        for(int i=2;i*i<=limit;++i) {
            if(prime[i]){
                for(int j=i*i;j<=limit;j+=i) {
                    prime[j]=false;
                }
            }
        }

        return prime;
    }
    int minJumps(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,vector<int>>mp;
        int maxi=0;
        for(int i=0;i<n;i++){
            mp[nums[i]].push_back(i);
            maxi=max(maxi,nums[i]);
        }

        sieve(maxi);

        queue<int>q;
        vector<bool>vis(n,0);

        q.push(0);
        vis[0]=1;
        unordered_set<int>seen;
        int steps=0;

        while(!q.empty()){
            int k=q.size();
            while(k--){
                int t=q.front();
                q.pop();

                if(t==n-1)return steps;

                //left
                if(t-1>=0 and !vis[t-1]){
                    vis[t-1]=1;
                    q.push(t-1);
                }
                //right
                if(t+1<n and !vis[t+1]){
                    vis[t+1]=1;
                    q.push(t+1);
                }

                if(seen.count(nums[t]))continue;

                //teleport
                int val=nums[t];
                if(prime[val]){
                    for(int j=val;j<=maxi;j+=val){
                        if(!mp.contains(j)){
                            continue;
                        }
                        for(int &jj:mp[j]){
                            if(!vis[jj]){
                                q.push(jj);
                                vis[jj]=1;
                            }
                        }
                    }
                    seen.insert(nums[t]);
                }
            }
            steps++;
        }
        return steps;
    }
};