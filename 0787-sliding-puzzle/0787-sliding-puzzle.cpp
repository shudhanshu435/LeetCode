class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        vector<vector<int>> choices = {{1, 3}, {0, 2, 4}, {1, 5},
                                       {0, 4}, {1, 3, 5}, {2, 4}};
        string target = "123450";
        unordered_set<string> vis;
        queue<string> q;
        string start = "";

        for (auto it : board) {
            for (auto e : it)
                start += e + '0';
        }
        int ans = 0;
        q.push(start);
        vis.insert(start);
        while (q.size()) {
            int n = q.size();
            while (n--) {
                auto curr = q.front();
                q.pop();
                if (curr == target)
                    return ans;
                int posi = curr.find('0');
                for (auto it : choices[posi]) {
                    string nxt = curr;
                    swap(nxt[it], nxt[posi]);
                    if (!vis.count(nxt)) {
                        vis.insert(nxt);
                        q.push(nxt);
                    }
                }
            }
            ans++;
        }
        // total possible combination of this string will 
        //be size("123450")! -->
        // 6! === 720 
        //therefore time complexity will be O(720)
        return -1;
    }
};