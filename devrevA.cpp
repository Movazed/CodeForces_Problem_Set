#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll maxSubarray(const vector<ll>& v) {
    ll cur = v[0], best = v[0];
    for (size_t i = 1; i < v.size(); ++i) {
        cur = max(v[i], cur + v[i]);
        best = max(best, cur);
    }
    return best;
}

ll minSubarray(const vector<ll>& v) {
    ll cur = v[0], best = v[0];
    for (size_t i = 1; i < v.size(); ++i) {
        cur = min(v[i], cur + v[i]);
        best = min(best, cur);
    }
    return best;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        int N; cin >> N;
        vector<ll> A(N);
        for (int i = 0; i < N; ++i) cin >> A[i];
        int M; cin >> M;
        vector<ll> B(M);
        for (int j = 0; j < M; ++j) cin >> B[j];

        ll maxA = maxSubarray(A);
        ll minA = minSubarray(A);
        ll maxB = maxSubarray(B);
        ll minB = minSubarray(B);

        ll ans1 = maxA * maxB;
        ll ans2 = minA * minB;
        ll ans = max(ans1, ans2);

        cout << ans << "\n";
    }
    return 0;
}