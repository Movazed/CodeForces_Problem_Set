#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int MAXM = 2e5 + 5;
int a[MAXM];
int maxInRange[MAXM][20]; // maxInRange[i][j] = max(a[i], a[i+1], ..., a[i+2^j-1])

int getMax(int l, int r) {
    if (l > r) return 0;
    int len = r - l + 1;
    int k = __builtin_clz(1) - __builtin_clz(len);
    return max(maxInRange[l][k], maxInRange[r - (1 << k) + 1][k]);
}

int main(){
    int n, m;
    cin >> n >> m;
    
    for (int i = 1; i <= m; i++) {
        cin >> a[i];
    }
    
    // Build sparse table for RMQ
    for (int i = 1; i <= m; i++) {
        maxInRange[i][0] = a[i];
    }
    
    for (int j = 1; (1 << j) <= m; j++) {
        for (int i = 1; i + (1 << j) - 1 <= m; i++) {
            maxInRange[i][j] = max(maxInRange[i][j-1], maxInRange[i + (1 << (j-1))][j-1]);
        }
    }
    
    int q;
    cin >> q;
    
    while (q--) {
        int xs, ys, xf, yf, k;
        cin >> xs >> ys >> xf >> yf >> k;
        
        // Check if distances are divisible by k
        if (abs(xf - xs) % k != 0 || abs(yf - ys) % k != 0) {
            cout << "NO\n";
            continue;
        }
        
        // If same column, we can always move vertically
        if (ys == yf) {
            cout << "YES\n";
            continue;
        }
        
        // Need to move horizontally
        // Find the maximum blocked height in the column range
        int left = min(ys, yf);
        int right = max(ys, yf);
        int maxBlocked = getMax(left, right);
        
        // The safe zone starts at maxBlocked + 1
        // We need both xs and xf to be >= maxBlocked + 1
        // And we need to be able to reach a common row
        int minRow = min(xs, xf);
        int maxRow = max(xs, xf);
        
        // Check if we can find a safe row to travel horizontally
        if (maxBlocked < minRow) {
            // We can travel at any row >= maxBlocked + 1 and <= minRow
            cout << "YES\n";
        } else if (maxBlocked + k <= n && maxRow >= maxBlocked + k) {
            // We can go up to a safe row (maxBlocked + k or higher)
            // and both positions can reach it
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}