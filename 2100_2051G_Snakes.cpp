#include <bits/stdc++.h>
using namespace std;
#define vpii vector<pair<int, int>>
#define vvii vector<vector<int>>
#define vi vector<int>
int main() {
  long long n, q, a; string c; cin >> n >> q;
  vpii d(n);
  vvii g(n, vi(n, 1));
  while (q-- and cin >> a >> c) {
    d[--a].second += c == "+";
    d[a].first += c == "-";
    for (int b = 0; b < n; b++) g[a][b] = max(d[a].second - d[b].first + 1, g[a][b]);
  }
  vvii dp(n, vi(1 << n, 1e9));
  for (int j = 0; j < n; j++) dp[j][1 << j] = d[j].second;
  for (int i = 1; i < (1 << n); i++) {
    for (int l = 0; l < n; l++) {
      int k = i ^ (1 << l);
      if (k > i) for (int j = 0; j < n; j++) dp[l][k] = min(dp[l][k], dp[j][i] + g[l][j]);
    }
  }
  int best = 1e9; for (auto &v: dp) best = min(best, v.back() + 1);
  cout << best << '\n';
}
