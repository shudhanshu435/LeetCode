class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> out_going(n , 0);
        for(int i = 0; i<n; i++)
        {
            out_going[i] = graph[i].size();
        }
        queue<int> que;
        for(int i = 0; i<n; i++)
        {
            if(out_going[i]==0)
            que.push(i);                
        }
        int x = 0;
        vector<vector<int>> adj(n);

        for(int i = 0; i<n; i++)
        {
            for(auto j : graph[i])
            {
                adj[j].push_back(i);
            }
        }

        int temp;

        while(!que.empty()){
            temp = que.front();
            que.pop();
            x++;
            for(auto i : adj[temp])
            {
                out_going[i]--;
                if(out_going[i]==0)
                {
                    que.push(i);
                }
            }
        }
        vector<int> ans(x);
        int index = 0;

        for(int i = 0; i<n; i++)
        {
            if(out_going[i]==0)
            ans[index++] = i;
        }

        return ans;
    }
};