#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX_N = 1e5 + 5;
int n, m, a[MAX_N], id[MAX_N];
ll prefixSum[MAX_N], minValue[MAX_N], result[MAX_N];
int validPositions[MAX_N];

// Comparator to sort indices by their corresponding values in array `a`
bool compareByValue(int i, int j) {
    return a[i] < a[j];
}

void solve() {
    // Input the size of the array
    cin >> n;

    // Read the array and initialize indices
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        id[i] = i;
    }

    // Sort indices based on the values of `a`
    sort(id + 1, id + n + 1, compareByValue);

    // Compute prefix sums based on the sorted indices
    for (int i = 1; i <= n; ++i) {
        prefixSum[i] = prefixSum[i - 1] + a[id[i]];
    }

    // Initialize the minimum value array
    minValue[0] = LLONG_MAX;
    for (int i = 1; i <= n; ++i) {
        minValue[i] = min(minValue[i - 1], prefixSum[i - 1] - a[id[i]]);
    }

    // Determine valid positions based on conditions
    m = 0;
    for (int i = 1; i <= n; ++i) {
        if (prefixSum[i - 1] < a[id[i]]) {
            validPositions[++m] = i;
        }
    }
    validPositions[m + 1] = n + 1;

    // Calculate results for each index
    for (int i = 1; i <= n; ++i) {
        if (minValue[i - 1] >= -a[id[i]]) {
            result[id[i]] = *upper_bound(validPositions + 1, validPositions + m + 1, i) - 2;
        } else {
            result[id[i]] = upper_bound(minValue + 1, minValue + i, a[id[i]], greater<int>()) - minValue - 1;
        }
    }

    // Output the results
    for (int i = 1; i <= n; ++i) {
        cout << result[i] << ' ';
    }
    cout << '\n';
}

int main() {
    int testCases;
    cin >> testCases;
    while (testCases--) {
        solve();
    }
    return 0;
}
