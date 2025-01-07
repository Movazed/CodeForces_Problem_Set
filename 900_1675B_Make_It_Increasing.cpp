#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool makeStrictlyIncreasing(vector<int> &a, int n) {
    for (int i = n - 2; i >= 0; i--) {
        if (a[i] >= a[i + 1]) {
            int operations = 0;
            while (a[i] >= a[i + 1] && a[i] > 0) {
                a[i] /= 2;
                operations++;
            }
            if (a[i] == 0 && a[i] >= a[i + 1]) return false;
        }
    }
    return true;
}

int countOperations(vector<int> &a, int n) {
    int total_operations = 0;
    for (int i = n - 2; i >= 0; i--) {
        int operations = 0;
        while (a[i] >= a[i + 1] && a[i] > 0) {
            a[i] /= 2;
            operations++;
        }
        total_operations += operations;
        if (a[i] == 0 && a[i] >= a[i + 1]) return -1;
    }
    return total_operations;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        int result = countOperations(a, n);
        cout << result << '\n';
    }
    return 0;
}
