#include<bits/stdc++.h>
#define ll long long
using namespace std;
#pragma GCC optimize("Ofast,unroll-loops")

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll t;
    cin >> t;

    while(t--){
        ll n, a, b;
        cin >> n >> a >> b;
        cout << ((a ^ b)&a>=b|(n^b)&1?"NO\n":"YES\n");
    }

    return 0;
}