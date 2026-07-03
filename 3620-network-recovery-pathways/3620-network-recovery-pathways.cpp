constexpr long long INF = 100'000'000'000'000;
int nbi[50001], srt[50000];
long long dis[50000];
char vis[50000];
pair<int,int> nbs[100000];

void tSort(int n, int &p) {
    if (vis[n]) return; else vis[n] = 1;
    for (int i = nbi[n], e = nbi[n+1]; i != e; ++i) tSort(nbs[i].first, p);
    if (p || !n) srt[p++] = n;
}

bool eval(int n, int x, long long k) {
    dis[0] = 0;
    for (int i = 1; i < n; ++i) {
        int nd = srt[i];
        long long dmin = INF;
        for (int j = nbi[nd], e = nbi[nd+1]; j != e; ++j) if (nbs[j].second >= x) {
            dmin = min(dmin, dis[nbs[j].first] + nbs[j].second);
        }
        dis[nd] = dmin;
    }
    return dis[srt[n-1]] <= k;
}

class Solution {
public:
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int N = size(online);
        fill(nbi, nbi+N, 0);
        for (const auto &e : edges) if (online[e[0]] && online[e[1]]) ++nbi[e[1]];
        for (int i = 1; i < N; ++i) nbi[i] += nbi[i-1];  nbi[N] = nbi[N-1];
        for (const auto &e : edges) if (online[e[0]] && online[e[1]]) nbs[--nbi[e[1]]] = { e[0], e[2] };

        int n=0;
        fill(vis, vis+N, 0); tSort(N-1, n);
        //for (int i = 0; i < n; ++i) cout << srt[i] << " "; cout << endl;
        fill(dis, dis+N, INF);
        if (!(n && eval(n,0,k))) return -1;

        int lo=INT_MAX,hi=0;
        for (int i = 0, e = nbi[N]; i != e; ++i) {
            int d = nbs[i].second;
            lo = min(lo, d); hi = max(hi, d);
        }
        while (lo < hi) {
            int m = (lo + hi + 1)/2;
            if (eval(n,m,k)) lo = m; else hi = m-1;
        }
        return lo;
    }
};