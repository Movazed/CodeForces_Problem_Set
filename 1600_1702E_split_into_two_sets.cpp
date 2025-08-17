#include <bits/stdc++.h>
using namespace std;

map<int, vector<int>> mp;
vector<bool> vis;

int dfs(int u) {
    vis[u] = true;
    for (int v : mp[u]) {
        if (!vis[v]) {
            return dfs(v) + 1;
        }
    }
    return 1;
}

void solve() {
    int n, x, y;
    cin >> n;
    mp.clear();
    vis.assign(n, false);
    bool fault = false;

    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        --x; --y;
        mp[x].push_back(y);
        mp[y].push_back(x);
        if (x == y || mp[x].size() > 2 || mp[y].size() > 2) {
            fault = true;
        }
    }

    if (fault) {
        cout << "NO\n";
        return;
    }

    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            if (dfs(i) % 2) {
                cout << "NO\n";
                return;
            }
        }
    }

    cout << "YES\n";
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
}
