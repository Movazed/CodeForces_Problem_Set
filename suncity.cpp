#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

#define ll long long
#define i128 __int128_t

using namespace std;

// A standard struct to represent a line y = mx + c
struct Line {
    ll m, c;

    ll eval(ll x) const {
        return m * x + c;
    }
};

// Convex Hull Trick data structure for finding the maximum value.
// It assumes that slopes of lines added are monotonic (either always increasing or always decreasing).
struct CHT {
    vector<Line> hull;

    void add(Line newline) {
        // Remove redundant lines from the back
        while (hull.size() >= 2) {
            Line l1 = hull[hull.size() - 2];
            Line l2 = hull[hull.size() - 1];
            // Using 128-bit integers to avoid overflow during cross-product calculation
            i128 val1 = (i128)(newline.c - l1.c) * (l1.m - l2.m);
            i128 val2 = (i128)(l2.c - l1.c) * (l1.m - newline.m);
            if (val1 <= val2) {
                hull.pop_back();
            } else {
                break;
            }
        }
        hull.push_back(newline);
    }

    ll query(ll x) {
        if (hull.empty()) {
            return -4e18; // Return a very small value if hull is empty
        }

        // Binary search for the line that gives the maximum value at x
        int l = 0, r = hull.size() - 1;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (hull[mid].eval(x) < hull[mid + 1].eval(x)) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        return hull[l].eval(x);
    }
};

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    if (n <= 1) {
        if (n == 1) cout << a[0] << "\n";
        else cout << 0 << "\n";
        return;
    }

    vector<ll> s(n, 0);
    s[0] = a[0];
    for (int i = 1; i < n; ++i) {
        s[i] = s[i - 1] + a[i];
    }

    auto get_s = [&](int i) {
        return (i < 0) ? 0LL : s[i];
    };

    ll initial_power = 0;
    for (int i = 0; i < n; ++i) {
        initial_power += a[i] * (i + 1);
    }

    ll max_delta = -4e18; 

    // Case 1: Move from i to j, where i > j (move left)
    CHT cht1;
    for (int i = 0; i < n; ++i) {
        ll val_j = cht1.query(a[i]);
        if (val_j > -3e18) {
             ll current_delta = val_j + get_s(i - 1) - (ll)i * a[i];
             max_delta = max(max_delta, current_delta);
        }
        cht1.add({(ll)i, -get_s(i - 1)});
    }

    // Case 2: Move from i to j, where i < j (move right)
    CHT cht2;
    for (int i = n - 1; i >= 0; --i) {
        ll val_j = cht2.query(a[i]);
        if (val_j > -3e18) {
            ll current_delta = val_j - ((ll)i * a[i] - get_s(i));
            max_delta = max(max_delta, current_delta);
        }
        cht2.add({(ll)i, -get_s(i)});
    }
    
    cout << initial_power + max_delta << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}