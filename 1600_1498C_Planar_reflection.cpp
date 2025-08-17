#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
const int MAXN = 1005;

int a[MAXN][MAXN];

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        // Initialize base case
        for (int j = 0; j <= n; ++j) {
            a[0][j] = 0;
        }
        a[0][0] = 1; // 1 way to partition 0 into 0 parts

        for (int i = 1; i <= k; ++i) {
            for (int j = 0; j <= n; ++j) {
                if (j == 0)
                    a[i][j] = 1;
                else
                    a[i][j] = (a[i][j - 1] + a[i - 1][n - j]) % MOD;
            }
        }

        cout << a[k][n] << '\n';
    }

    return 0;
}
