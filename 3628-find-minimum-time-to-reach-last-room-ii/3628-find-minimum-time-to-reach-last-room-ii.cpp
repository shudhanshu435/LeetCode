struct Node {
    long long t;
    int id;
    bool operator>(Node const& o) const { return t > o.t; }
};
class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size(), m = moveTime[0].size();
        int N = n * m * 2;
        const long long INF = numeric_limits<long long>::max() / 2;
        vector<long long> dist(N, INF);
        auto idx = [&](int x, int y, int p) {
            return ((x * m + y) << 1) | p;
        };
        dist[idx(0,0,0)] = 0;
        vector<Node> buf;
        buf.reserve(N);
        priority_queue<Node, vector<Node>, greater<Node>> pq(greater<Node>(), move(buf));
        pq.push({0, idx(0,0,0)});
        static const int dx[4] = {1,-1,0,0};
        static const int dy[4] = {0,0,1,-1};
        while (!pq.empty()) {
            auto [t, id] = pq.top(); pq.pop();
            if (t > dist[id]) continue;
            int p = id & 1;
            int flat = id >> 1;
            int x = flat / m, y = flat % m;
            if (x == n-1 && y == m-1) return int(t);
            long long cost = (p == 0 ? 1 : 2);
            int np = p ^ 1;
            for (int k = 0; k < 4; ++k) {
                int nx = x + dx[k], ny = y + dy[k];
                if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                long long wait = moveTime[nx][ny];
                long long nt = max(t, wait) + cost;
                int nid = idx(nx, ny, np);
                if (nt < dist[nid]) {
                    dist[nid] = nt;
                    pq.push({nt, nid});
                }
            }
        }
        return -1;
    }
};