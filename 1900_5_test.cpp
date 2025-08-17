#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];

        auto check = [&](int v,int&L,int&R) -> bool {
            // pref[0] = 0; pref[i] = sum of first i mapped values
            vector<int> pref(n + 1, 0);
            for (int i = 1; i <= n; ++i) {
                pref[i] = pref[i - 1] + (a[i - 1] >= v ? 1 : -1);
            }
            int minPref = 0;
            int minIdx = 0; // index where minPref occurs
            for (int i = 1; i <= n; ++i) {
                if (i >= k) {
                    // Expand the set of candidate starts to include index i - k
                    if (pref[i - k] < minPref) {
                        minPref = pref[i - k];
                        minIdx = i - k;
                    }
                    // If sum over (minIdx+1 .. i) >= 0, we found a valid subarray
                    if (pref[i] - minPref >= 0) {
                        L = minIdx + 1; // 1-based
                        R = i;          // 1-based
                        return true;
                    }
                }
            }
            return false;
        };

        int lo = 1, hi = n;
        int bestV = 1, ansL = 1, ansR = k; // initialize with something valid when v = 1
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            int L = -1, R = -1;
            if (check(mid, L, R)) {
                bestV = mid;
                ansL = L;
                ansR = R;
                lo = mid + 1; // try to increase v
            } else {
                hi = mid - 1;
            }
        }

        // Output the maximum submedian and one valid subarray
        cout << bestV << ' ' << ansL << ' ' << ansR << '\n';
    }
    return 0;
}