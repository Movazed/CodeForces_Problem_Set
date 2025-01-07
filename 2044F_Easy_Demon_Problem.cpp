#include <bits/stdc++.h>
using namespace std;

// Constants
static const int MAXX = 200000;

// Precompute divisors
vector<vector<int>> precompute_divisors(int max_val) {
    vector<vector<int>> divisors(max_val + 1);
    for (int i = 1; i <= max_val; i++) {
        for (int j = i; j <= max_val; j += i) {
            divisors[j].push_back(i);
        }
    }
    return divisors;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Precompute divisors
    auto divisors = precompute_divisors(MAXX);

    // Input
    int n, m, q;
    cin >> n >> m >> q;

    vector<long long> a(n), b(m);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int j = 0; j < m; j++) cin >> b[j];

    // Compute sums
    long long Sa = accumulate(a.begin(), a.end(), 0LL);
    long long Sb = accumulate(b.begin(), b.end(), 0LL);

    // Compute normalized arrays A' and B'
    vector<long long> a_prime(n), b_prime(m);
    for (int i = 0; i < n; i++) a_prime[i] = a[i] * m - Sa;
    for (int j = 0; j < m; j++) b_prime[j] = b[j] * n - Sb;

    // Insert into hash sets
    unordered_set<long long> setA(a_prime.begin(), a_prime.end());
    unordered_set<long long> setB(b_prime.begin(), b_prime.end());

    // Answer queries
    while (q--) {
        long long x;
        cin >> x;

        if (x == 0) {
            // Check for zero
            if (setA.find(0) != setA.end() || setB.find(0) != setB.end()) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
            continue;
        }

        long long X = abs(x); // Absolute value of x
        if (X <= MAXX) {
            bool possible = false;
            for (auto d : divisors[X]) {
                long long D2 = x / d; // Ensure signed division
                if ((setA.find(d) != setA.end() && setB.find(D2) != setB.end()) ||
                    (setA.find(-d) != setA.end() && setB.find(-D2) != setB.end())) {
                    possible = true;
                    break;
                }
            }
            cout << (possible ? "YES\n" : "NO\n");
        } else {
            // |x| > MAXX should not occur under given constraints
            cout << "NO\n";
        }
    }

    return 0;
}
