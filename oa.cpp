#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define all(x) (x).begin(), (x).end()
using ll = long long;
const int INF = 1e9+7;

// Helper for BFS: returns shortest distance from src to all nodes
vector<int> bfs(int src, const vector<vector<int>>& g) {
    int n = g.size();
    vector<int> dist(n, INF);
    queue<int> q;
    dist[src] = 0;
    q.push(src);
    while (!q.empty()) {
        int v = q.front(); q.pop();
        for (int u : g[v]) {
            if (dist[u] > dist[v] + 1) {
                dist[u] = dist[v] + 1;
                q.push(u);
            }
        }
    }
    return dist;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int t; cin >> t;
    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;
        vector<vector<int>> g(n+1); // must be inside the loop!
        for (int i = 0; i < m; ++i) {
            int u, v; cin >> u >> v;
            g[u].pb(v); g[v].pb(u);
        }
        vector<int> enemy(k);
        for (int& x : enemy) cin >> x;

        auto bfs = [&](int src) {
            vector<int> dist(n+1, INF);
            queue<int> q;
            dist[src] = 0;
            q.push(src);
            while (!q.empty()) {
                int v = q.front(); q.pop();
                for (int u : g[v]) {
                    if (dist[u] > dist[v] + 1) {
                        dist[u] = dist[v] + 1;
                        q.push(u);
                    }
                }
            }
            return dist;
        };

        auto d1 = bfs(1);
        auto dn = bfs(n);

        vector<int> min_enemy(n+1, INF);
        for (int e : enemy) min_enemy[e] = min(min_enemy[e], d1[e]);

        int res = INF;
        for (int u = 1; u <= n; ++u) {
            if (d1[u] < min_enemy[u]) {
                res = min(res, d1[u] + dn[u]);
            }
        }
        cout << (res == INF ? -1 : res) << '\n';
    }
    return 0;
}