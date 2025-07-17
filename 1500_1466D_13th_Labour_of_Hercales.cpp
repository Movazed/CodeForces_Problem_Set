#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 100010;

int d[MAXN];
long long a[MAXN], b[2 * MAXN];

int main() {
    int T, n, u, v, cnt;
    cin >> T;
    while (T--) {
        cin >> n;
        cnt = 0;
        long long ans = 0;
        
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            ans += a[i];
            d[i] = 0; // Reset degree array
        }
        
        for (int i = 1; i < n; i++) {
            cin >> u >> v;
            d[u]++;
            d[v]++;
        }
        
        for (int i = 1; i <= n; i++) {
            d[i]--;
            while (d[i] > 0) {
                b[++cnt] = a[i];
                d[i]--;
            }
        }
        
        sort(b + 1, b + cnt + 1);
        cout << ans << ' ';
        
        for (int i = cnt; i >= 1; i--) {
            ans += b[i];
            cout << ans << ' ';
        }
        
        cout << endl;
    }
    return 0;
}