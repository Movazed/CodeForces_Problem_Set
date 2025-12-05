#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vll vector<ll>

void solve() {
    int n; cin >> n;
    vll a(n);
    ll M = -1; int I = -1;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] > M) M = a[i], I = i;
    }
    vll b;
    for (int i = 0; i < n; i++) b.push_back(a[(I + 1 + i) % n]);
    stack<ll> s; ll c = 0;
    for (ll x : b) {
        while (!s.empty() && s.top() <= x) {
            ll m = s.top(); s.pop();
            c += s.empty() ? x : min(s.top(), x);
        }
        s.push(x);
    }
    cout << c << "\n";
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}