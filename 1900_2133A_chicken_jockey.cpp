#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll t, n, a[200005];
#pragma GCC optimize("Ofast,unroll-loops")
ll f[200005];
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n;
        for(ll i = 1; i <= n; i++) cin >> a[i];
        f[1] = a[1];
        for(int i = 2; i <= n; i++){
            f[i] = min(f[i - 1] + a[i] - 1, f[i - 2] + a[i - 1] + (ll)max(a[i] - i + 1, 0LL));
            cout << f[n] << '\n';
        }
        return 0;
    }
}