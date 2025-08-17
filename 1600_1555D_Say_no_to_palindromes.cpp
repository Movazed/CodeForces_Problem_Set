#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("Ofast,unroll-loops")
// #pragma GCC target("avx,avx2,avx512,fma")

#define ll long long
#define nl '\n'

string patterns[6] = {"abc", "acb", "bac", "bca", "cab", "cba"};

void solve() {
    int n, m;
    string str;
    cin >> n >> m >> str;

    // Precompute prefix mismatches for all 6 patterns
    vector<vector<int>> s(6, vector<int>(n + 1, 0));
    for (int t = 0; t < 6; t++) {
        for (int i = 1; i <= n; i++) {
            s[t][i] = s[t][i - 1] + (str[i - 1] != patterns[t][(i - 1) % 3]);
        }
    }

    // Answer m queries
    while (m--) {
        int l, r;
        cin >> l >> r;
        int ans = INT_MAX;
        for (int t = 0; t < 6; t++) {
            ans = min(ans, s[t][r] - s[t][l - 1]);
        }
        cout << ans << nl;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc = 1;
    cin >> tc;
    while (tc--) {
        solve();
    }

    return 0;
}
