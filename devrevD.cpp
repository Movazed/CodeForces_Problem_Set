#include <bits/stdc++.h>
using namespace std;

static long long isqrt_bounded(long long n, long long Rmax) {
    long long lo = 0, hi = Rmax, ans = 0;
    while (lo <= hi) {
        long long mid = (lo + hi) >> 1;
        long long mid2 = mid * mid;
        if (mid2 <= n) { ans = mid; lo = mid + 1; }
        else hi = mid - 1;
    }
    return ans; // floor(sqrt(n)) but limited to Rmax
}

int Solution(int x1, int y1, int x2, int y2, int xc, int yc, int R) {
    using ll = long long;
    ll X1 = x1, Y1 = y1, X2 = x2, Y2 = y2;
    ll XC = xc, YC = yc, RR = R;
    ll R2 = RR * RR;

    ll lx = max(X1, XC - RR);
    ll rx = min(X2, XC + RR);
    if (rx < lx) return 0;

    ll total = 0;
    for (ll x = lx; x <= rx; ++x) {
        ll dx = x - XC;
        ll rem = R2 - dx * dx;
        if (rem < 0) continue;
        ll t = isqrt_bounded(rem, RR);      // maximum |y - yc|
        ll ly = max(Y1, YC - t);
        ll ry = min(Y2, YC + t);
        if (ry >= ly) total += (ry - ly + 1);
    }

    return (int)total;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int x1, y1, x2, y2;
    int xc, yc, R;
    if (!(cin >> x1 >> y1 >> x2 >> y2)) return 0;
    cin >> xc >> yc >> R;

    cout << Solution(x1, y1, x2, y2, xc, yc, R) << '\n';
    return 0;
}