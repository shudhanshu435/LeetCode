class Solution {
public:
    int dfs(int node, vector<int> &visited, vector<int> &pathVisit, vector<vector<int>> &adj, vector<vector<int>> &freq, string &colors){
        if(pathVisit[node]){
            return INT_MAX;
        }
        if(visited[node]){
            return freq[node][26];
        }
        visited[node] = 1;
        pathVisit[node] = 1;

        for(auto nei: adj[node]){

            int val = dfs(nei, visited, pathVisit, adj, freq, colors);
            if(val==INT_MAX) return val;

            for(int i = 0; i<26; i++){
                freq[node][i]=max(
                    freq[node][i], 
                    freq[nei][i]
                );
            }
        }
        pathVisit[node]=0;
        freq[node][colors[node]-'a']+=1;
        int maxi = *max_element(freq[node].data(), freq[node].data()+26);
        return freq[node][26] = maxi;
    }
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.length();
        vector<int> visited(n, 0);
        vector<vector<int>> freq(n, vector<int>(27, 0));
        vector<vector<int>> adj(n);
        for(auto e: edges){
            adj[e[0]].push_back(e[1]);
        }

        int res = 0;
            vector<int> pathVisit(n, 0);
        for(int i = 0; i<n; i++){
            if(!visited[i]){
                res = max(res, dfs(i, visited, pathVisit, adj, freq, colors));
                if(res==INT_MAX) return -1;
            }
        }
        return res;
    }
};