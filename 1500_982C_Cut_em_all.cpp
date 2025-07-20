#include <bits/stdc++.h>
using namespace std;

vector<int> g[100005];
int a = -1;

int dfs(int u, int p) {
    int s = 0;
    for (int v : g[u]) {
        if (v != p) {
            s += dfs(v, u);
        }
    }
    a += s % 2;
    return s + 1;
}

int main() {
    int n;
    cin >> n;
    if (n % 2) {
        cout << -1 << endl;
        return 0;
    }
    
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    
    dfs(1, 0);
    cout << a << endl;
    
    return 0;
}