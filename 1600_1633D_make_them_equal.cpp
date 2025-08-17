#include <bits/stdc++.h>
using namespace std;

const int MAX_A = 1001; // Since max a[i] must be within this for g[]
const int MAX_K = 1e4 + 5; // Adjust depending on max k

int g[MAX_A]; // g[i] = cost to reach i
int dp[MAX_K];

void precompute() {
    const int INF = 1e9;
    fill(g, g + MAX_A, INF);
    g[1] = 0;

    for (int i = 1; i < MAX_A; i++) {
        for (int j = 1; j <= i; j++) {
            int to = i + i / j;
            if (to < MAX_A)
                g[to] = min(g[to], g[i] + 1);
        }
    }
}

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n), c(n); // a[i] = value, c[i] = reward
    for (int &x : a) cin >> x;
    for (int &x : c) cin >> x;

    int total_cost = 0;
    vector<int> cost(n);
    for (int i = 0; i < n; i++) {
        cost[i] = g[a[i]];
        total_cost += cost[i];
    }

    int max_k = min(k, total_cost);
    fill(dp, dp + max_k + 1, 0);

    for (int i = 0; i < n; i++) {
        for (int j = max_k; j >= cost[i]; j--) {
            dp[j] = max(dp[j], dp[j - cost[i]] + c[i]);
        }
    }

    cout << *max_element(dp, dp + max_k + 1) << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    precompute(); // Precompute cost g[i]

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}