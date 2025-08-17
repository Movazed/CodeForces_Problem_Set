#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll N = 200020;
ll n, q, T, a[N], dp[N][25];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> T;
    while (T--) {
        cin >> n >> q;
        for (ll i = 1; i <= n; i++) cin >> a[i];

        // build dp for differences
        for (ll i = 1; i < n; i++) dp[i][0] = abs(a[i] - a[i + 1]);

        // sparse table construction
        for (ll j = 1; j <= 20; j++) {
            for (ll i = 1; i + (1 << j) - 1 <= n - 1; i++) {
                dp[i][j] = __gcd(dp[i][j - 1], dp[i + (1 << (j - 1))][j - 1]);
            }
        }

        // answer queries
        while (q--) {
            ll l, r;
            cin >> l >> r;
            if (l == r) {
                cout << "0 ";
            } else {
                ll k = log2(r - l);
                cout << __gcd(dp[l][k], dp[r - (1 << k)][k]) << " ";
            }
        }
        cout << '\n';
    }
    return 0;
}
