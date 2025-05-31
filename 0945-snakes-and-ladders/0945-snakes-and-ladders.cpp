class Solution {
 public:
  int snakesAndLadders(vector<vector<int>>& board) {
    const int n = board.size();
    int res = 0;
    queue<int> que{{1}};
    vector<bool> visited(1 + n * n);
    vector<int> A(1 + n * n);

    for (int i = 0; i < n; ++i){
       for (int j = 0; j < n; ++j){
         A[(n - 1 - i) * n + (n - i & 1 ? j + 1 : n - j)] = board[i][j];
       }
    }
    while (!que.empty()) {
      ++res;
      for (int sz = que.size(); sz > 0; --sz) {
          const int curr = que.front();
          que.pop();
          for (int next = curr + 1; next <= min(curr + 6, n * n); ++next) {
              const int dest = A[next] > 0 ? A[next] : next;
              if (dest == n * n)
                return res;
              if (visited[dest])
                continue;
              que.push(dest);
              visited[dest] = true;
        }
      }
    }
    return -1;
  }
};